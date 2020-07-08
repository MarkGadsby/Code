    <?php
    $myfile = fopen("MusicPlayer.config", "r+") or die("Unable to open file!");
    
    $stop; 
    $tier; 
    
    while (!feof($myfile))
    {
        $line = fgets($myfile);
        $explodedLine = explode('=',$line);

        if ($explodedLine[0] == 'Stop') // reading stop line
        {
            $stop = $line;

            if ($_GET['arg_1'] == "Stop")
                $stop = $explodedLine[0]."=".$_GET["arg_2"]."\n";
        }

        if ($explodedLine[0] == 'Tier') // reading Tire line
        {
            $tier = $line;

            if ($_GET['arg_1'] == "Tier")
                $tier = $explodedLine[0]."=".$_GET["arg_2"];
        }
    } 
    file_put_contents('MusicPlayer.config',$stop.$tier);
    fclose($myfile);
    ?>
