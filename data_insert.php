<?php include"connect.php";

if (isset($_GET['hotelkey'])) {
   $hotelkey = htmlspecialchars($_GET['hotelkey']);
   session_id($hotelkey);
}


session_start();


$id = $_SESSION["device_id"];
$temp = $_GET["temp"];


if (isset($_SESSION["device_id"]) && $_SESSION["device_id"]!=0) {
    

  // Doe de insert
    $query = "INSERT INTO data (id, device_id, temperature, date_time) VALUES (NULL, '$id', '$temp', current_timestamp())";
   
    if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);
    
     echo $_SESSION["device_id"];


} else {
    
   echo "0";
}

?>
