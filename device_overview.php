<?php	
	error_reporting(E_ALL);
	ini_set('display_errors', 1);
	ini_set('display_startup_errors', 1);
	
	include("connect.php");
	
	echo "<html>
	<head>
	</head>
	<body>";
	
	echo $query = "SELECT de.id as dev_id,d.temperature,d.date_time,de.name FROM data d
    LEFT JOIN device de ON (d.device_id = de.id)";
	echo "<br /><br />";
	if (!($result = $mysqli->query($query)))
			showerror($mysqli->errno,$mysqli->error);
	
	$show = "<table>";
	
	$row = $result->fetch_assoc();
	
	do {
		$show.= 
        "<tr>
        <td>" . $row["name"] . "</td>
        <td>" . $row["temperature"] . "</td>
         <td>" . $row["date_time"] . "</td>
        </tr>";
	} while ($row = $result->fetch_assoc());
	$show .= "</table><br /><br />";
	echo $show;
		
	echo "</body>
	</html>";
	
?>
