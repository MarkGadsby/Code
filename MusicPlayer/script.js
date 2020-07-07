function GetCovers(str)
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() 
    {
        if (this.readyState == 4 && this.status == 200) 
        {
            document.getElementById("ret").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "GetCovers.php?arg1=" + str, true);
    xhttp.send();
}

function SendCover(str)
{
    var start = str.search("/Music");

    var param = ".";

    param += str.substring(start,str.search("Cover.jpg"));

    console.log(param);

    var param = encodeURIComponent(param);

    console.log(param);

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "NewAlbum.php?arg_1=" + "Title&" + "arg_2=" + param, true);
    xhttp.send();
}

function ClickStopsPlay(checked) 
{
    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "NewAlbum.php?arg_1=" + "Stop&" + "arg_2=" + checked, true);
    xhttp.send();
} 