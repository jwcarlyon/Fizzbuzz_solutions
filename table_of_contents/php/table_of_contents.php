<!DOCTYPE html>
<html>
<body>

<h1>Table of Contents</h1>

<?php
    require __DIR__ . '/vendor/autoload.php';
    $parser = new \Smalot\PdfParser\Parser();

    //gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dNOPAUSE -dQUIET -dBATCH -sOutputFile=new_gri_report.pdf gri_report.pdf
    $pdf = $parser->parseFile('resources/new_gri_report.pdf');
    $table_of_contents = array();
    $table_text = "";
    for($page = 1; $page < 3; $page += 1)
    {
        $text = $pdf->getPages()[$page]->getText();
        $table_of_contents = array_merge($table_of_contents, create_chapter_array($text));
    }
    print_r($table_of_contents);

    function create_chapter_array($page)
    {
        $lines = explode("Disclosure", $page);
        $chapter_array = array();
        $all_periods_regex = '#\\.+#';
        $chapter_number_hyphenated_regex = '/\d{1,3}-\d{1,3}/';
        foreach($lines as $line)
        {
            $new_line = preg_replace($all_periods_regex, '', $line);
            if (preg_match($chapter_number_hyphenated_regex, $new_line))
            {
                array_push($chapter_array, new Chapter($new_line));
            }
        }
        return $chapter_array;
    }

    class Chapter
    {
        public $title;
        public $page;
        public function __construct($chapter_string)
        {
          $found_page = 'no page found';
          $last_hyphen_position = strripos($chapter_string, '-');
          $found_title = 'Disclosure ' . substr($chapter_string, 0, $last_hyphen_position);
          $chapter_string = substr($chapter_string, $last_hyphen_position);
          $multiple_digits_regex = '/\d+/';
          foreach(explode(' ', $chapter_string) as $word)
          {
              if(preg_match($multiple_digits_regex, $word))
              {
                  $found_page = $word;
                  break;
              } else {
                  $found_title .= " $word";
              }
          }
          $this->title = "$found_title<br>";
          $this->page = "$found_page<br>";
        }
    }
?>

</body>
</html>
