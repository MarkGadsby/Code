<?php
    $myfile = fopen("MusicPlayer.config", "r+") or die("Unable to open file!");
   
    $bStop;

    while (!feof($myfile))
    {
        $line = fgets($myfile);
        $line = rtrim($line); 
        $explodedLine = explode('=',$line);

        if ($explodedLine[0] == 'Stop') // reading Stop line
            $bStop = filter_var($explodedLine[1], FILTER_VALIDATE_BOOLEAN);
    } 
    fclose($myfile);

    $CheckedString = "unchecked"; 

    if ($bStop)
        $CheckedString = "checked";

    echo "<input type=\"checkbox\" id=\"stop_play\" name=\"stop_check\" $CheckedString onclick=\"ClickStopsPlay(this.checked)\">";
    echo "<label for=\"stop_play\">Stop playing after this track</label>";
?>
