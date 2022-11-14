<!DOCTYPE html>
<html>
<body>

<h1>Table of Contents</h1>

<?php
    require __DIR__ . '/vendor/autoload.php';
    $parser = new \Smalot\PdfParser\Parser();

    function chapters_as_array($page)
    {
        $lines = explode("Disclosure", $page);
        $table_lines = array();
        foreach($lines as $line)
        {
            $new_line = preg_replace('#\\.+#', '', $line);
            if (preg_match('/\d{1,3}-\d{1,3}/', $new_line))
            {
                array_push($table_lines, $new_line);
            }
        }
        var_dump($table_lines);
        return $table_lines;
    }
    //gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dNOPAUSE -dQUIET -dBATCH -sOutputFile=new_gri_report.pdf gri_report.pdf
    $pdf = $parser->parseFile('resources/new_gri_report.pdf');
    $table_of_contents = array();
    for($page = 1; $page < 3; $page += 1)
    {
        $text = $pdf->getPages()[$page]->getText();
        $table_of_contents = array_merge($table_of_contents, chapters_as_array($text));
    }
    var_dump($table_of_contents);
?>

</body>
</html>
