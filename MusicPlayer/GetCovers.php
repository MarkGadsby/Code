<?php

// Get connection 
$Connection = mysqli_connect("localhost", "root", "root","Albums");

// Check connection
if (!$Connection) 
  die("Connection failed: ".mysqli_connect_error());

$sql    = "SELECT Path,Title FROM Albums ORDER BY Artist"; 
$result = $Connection->query($sql);

if ($result->num_rows > 0) 
{
  while ($row = $result->fetch_assoc()) 
  {
    $CoverPath = $row["Path"]."Cover.jpg";
    $Title = $row["Title"];
    echo "<img src=\"".$CoverPath."\" onclick=\"SendCover(this.src)\" title=\"".$Title."\" alt=\"".$Title."\">";
  }
} 
// Close connection
$Connection->close();
?>
