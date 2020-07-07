    <?php
    $myfile = fopen("playlist", "r+") or die("Unable to open file!");
    
    $title;
    $stop; 
    
    while (!feof($myfile))
    {
        $line = fgets($myfile);
        $explodedLine = explode('=',$line);

        if ($explodedLine[0] == "Title") // reading title line
        {
            $title = $line;

            if ($_GET['arg_1'] == "Title")
            {
                $decodedArg = urldecode($_GET["arg_2"]);
                $title = $explodedLine[0]."=".$decodedArg."\r\n";
            }
        }

        if ($explodedLine[0] == 'Stop') // reading stop line
        {
            $stop = $line;

            if ($_GET['arg_1'] == "Stop")
                $stop = $explodedLine[0]."=".$_GET["arg_2"];
        }
    } 
    file_put_contents('playlist', $title.$stop);
    fclose($myfile);
    ?>
