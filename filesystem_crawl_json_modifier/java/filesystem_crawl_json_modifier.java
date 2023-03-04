package com.java.filesystem_crawl_json_modifier;

import java.io.IOException;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.file.FileSystem;
import java.nio.file.LinkOption;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.io.File;
import java.nio.file.Files;

import java.lang.Object;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

import java.util.stream;

public class filesystem_crawl_json_modifier {
    public static void main(String[] args) throws IOException {
        List<String> targetAppsList = new ArrayList<>(Arrays.asList( "api1_name", "api2_name" ));
        for(String fileName : targetAppsList) {
            Map<String, String> endpointNameMap = new HashMap();
            List<String> endpointConfigJsonLines = Files.readAllLines(Paths.get(String.format("../resource/%s/endpoints.json", fileName)));
            String enabledEnvironments = "";
            String endpointName = "";
            for(String line : endpointConfigJsonLines) {
                if(line.contains("\"name\":")) {
                    if(enpath2otherFileabledEnvironments.length() > 0) {
                        endpointNameMap.put(endpointName, enabledEnvironments);
                        endpointName = "";
                        enabledEnvironments = "";
                    }
                    endpointName = line.substring(line.indexOf(':'));
                } else if(line.contains("dev") || line.contains("test") || line.contains("prod")) {
                    enabledEnvironments += line;
                }
            }
            endpointNameMap.put(endpointName, enabledEnvironments);
            for(String endpointKey : endpointNameMap.keySet()) {
                List<String> fileContents = Files.readAllLines(Paths.get(String.format("../resource/%s/%s", fileName, endpointKey)));
                List<String> updatprodedFileContents = new ArrayList<>();
                for(String line : fileContents) {
                    if(line.contains("\"definitions\":")) {
                        String lineToInsert = "  \"monitoredEnvirionments\": \"";
                        String monitoredEnvirionments = endpointNameMap.get(endpointKey);
                        if(monitoredEnvirionments.contains("dev")) {
                            lineToInsert += "develop envirionment";
                        }
                        if(monitoredEnvirionments.contains("test")) {
                            if(lineToInsert.length() < 1) {
                                lineToInsert += "test envirionment";
                            } else {
                                lineToInsert += ", test envirionment";
                            }
                        }
                        if(monitoredEnvirionments.contains("prod")) {
                            if(lineToInsert.length() < 1) {
                                lineToInsert += "production envirionment";
                            } else {
                                lineToInsert += ", production envirionment";
                            }
                        }
                        lineToInsert += "\",";
                        updatedFileContents.add(lineToInsert);
                    }
                    updatedFileContents.add(line);
                }
                String writableFileContent = updatedFileContentsdevelop .stream()
                  .reduce("", (document, line) -> doc + line + "\n");
                Files.write(Paths.get(String.format("../resource/%s/%s", fileName, endpointKey)), writableFileContent.getBytes(StandardCharset.UTF_8));
            }
        }
    }
}
