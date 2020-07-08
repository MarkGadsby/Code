function Initialise()
{
    GetRadios();    // which includes setting the correctly checked tier 
    GetCheckbox()
}

setTimeout(function()
{
    TierSwitch(false);
},500);

function GetRadios()
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() 
    {
        if (this.readyState == 4 && this.status == 200) 
        {
            document.getElementById("TopMenu").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "GetRadios.php", true);
    xhttp.send();
}

function GetCovers(tier)
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() 
    {
        if (this.readyState == 4 && this.status == 200) 
        {
            document.getElementById("CoversSpace").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "GetCovers.php?tier_arg=" + tier, true);
    xhttp.send();
}

function GetArtistsFromHint(hint)
{
    console.log(hint);
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() 
    {
        if (this.readyState == 4 && this.status == 200) 
        {
            document.getElementById("CoversSpace").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "FindArtist.php?substring_arg=" + hint, true);
    xhttp.send();
}

function GetCheckbox()
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() 
    {
        if (this.readyState == 4 && this.status == 200) 
        {
            document.getElementById("BottomMenu").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "GetCheckbox.php", true);
    xhttp.send();
}

function SendCover(str)
{
    var start = str.search("/Music");

    var param = ".";

    param += str.substring(start,str.search("Cover.jpg"));

    param = encodeURIComponent(param);

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "NewAlbum.php?arg_1=" + "AlbumPath&" + "arg_2=" + param, true);
    xhttp.send();
}

function TierSwitch(bWriteToFile)
{
    var Tier = 0;

    if (document.getElementById("tier_one").checked)
    {
        Tier = 1;
        GetCovers(2);
        document.getElementById("artist_name").style.display = 'none'; 
    }

    if (document.getElementById("tier_two").checked)
    {
        Tier = 2;
        GetCovers(1);
        document.getElementById("artist_name").style.display = 'none'; 
    }

    if (document.getElementById("tier_three").checked)
    {
        Tier = 3;
        GetCovers(0);
        document.getElementById("artist_name").value = "";
        document.getElementById("artist_name").style.display = 'inline'; 
    }

    if (bWriteToFile)
    {
        var xhttp = new XMLHttpRequest();

        xhttp.open("GET", "Config.php?arg_1=" + "Tier&" + "arg_2=" + Tier, true);
        xhttp.send();
    }
}

function ClickStopsPlay(checked) 
{
    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "Config.php?arg_1=" + "Stop&" + "arg_2=" + checked, true);
    xhttp.send();
} 