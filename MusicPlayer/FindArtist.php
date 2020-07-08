<?php

// Get connection 
$Connection = mysqli_connect("localhost", "root", "root","Albums");

// Check connection
if (!$Connection) 
  die("Connection failed: ".mysqli_connect_error());

$subStr = $_GET["substring_arg"];   
$sql    = "SELECT Artist,Path,Title FROM Albums WHERE Artist LIKE '$subStr%' ORDER BY Artist"; 

$result = $Connection->query($sql);

if ($result->num_rows > 0) 
{
  while ($row = $result->fetch_assoc()) 
  {
    $CoverPath = $row["Path"]."Cover.jpg";
    $Title = $row["Title"];
    $Tooltip = $Title." by ".$row["Artist"];
    echo "<img src=\"".$CoverPath."\" onclick=\"SendCover(this.src)\" title=\"".$Tooltip."\" alt=\"".$Title."\">";
  }
} 
// Close connection
$Connection->close();
?>
