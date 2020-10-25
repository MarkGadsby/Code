    <?php
    $myfile = fopen("NowPlaying", "r+") or die("Unable to open file!");
    
    $albumpath;
    
    while (!feof($myfile))
    {
        $line = fgets($myfile);
        $explodedLine = explode('=',$line);

        if ($explodedLine[0] == "AlbumPath") // reading title line
        {
            $albumpath = $line;

            if ($_GET['arg_1'] == "AlbumPath")
            {
                $decodedArg = urldecode($_GET["arg_2"]);
                $albumpath = $explodedLine[0]."=".$decodedArg;
            }
        }
    } 
    file_put_contents('NowPlaying',$albumpath);
    fclose($myfile);
    ?>
