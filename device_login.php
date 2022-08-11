<?php include"connect.php";

session_start();


$id = $_GET["id"];
$wachtwoord = $_GET["wachtwoord"];


$query = "SELECT * FROM device WHERE id = $id AND wachtwoord = '$wachtwoord'";


if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);


$row = $result->fetch_assoc();


if ($id == $row["id"]){
    echo session_id();
    $_SESSION["device_id"]=$row["id"];
    }
    else{
        echo 0;
    }
    
?>
