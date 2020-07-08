<?php
    $myfile = fopen("MusicPlayer.config", "r+") or die("Unable to open file!");
   
    while (!feof($myfile))
    {
        $line = fgets($myfile);
        $explodedLine = explode('=',$line);

        if ($explodedLine[0] == 'Tier') // reading Tire line
            $tier = intval($explodedLine[1]);
    } 
    fclose($myfile);

    $T1 = "unchecked";
    $T2 = "unchecked";
    $T3 = "unchecked";

    switch ($tier)
    {
    case 1:
        {
            $T1 = "checked";
            break;
        }
    case 2:
        {
            $T2 = "checked";
            break;
        }
    case 3:
        {
            $T3 = "checked";
            break;
        }
    }

    echo "<input type=\"radio\" id=\"tier_one\" name=\"tiers\" $T1 onclick=\"TierSwitch(true)\">";
    echo "<label for=\"tier_one\">Tier One</label>";
    echo "<input type=\"radio\" id=\"tier_two\" name=\"tiers\" $T2 onclick=\"TierSwitch(true)\">";
    echo "<label for=\"tier_two\">Tier Two</label>";
    echo "<input type=\"radio\" id=\"tier_three\" name=\"tiers\" $T3 onclick=\"TierSwitch(true)\">";    
    echo "<label for=\"tier_three\">Tier Three</label>";
    echo "<input type=\"text\" id=\"artist_name\" name=\"artist_name\" onkeyup=\"GetArtistsFromHint(this.value)\">";
?>
