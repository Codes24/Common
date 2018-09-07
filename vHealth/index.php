<!DOCTYPE html>
<html>
<head>
	<title>Data</title>
	<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
<h2>Data</h2>
<table>
	<tr>
		<td>id</td>
		<td>time</td>
		<td>username</td>
		<td>data</td>
	</tr>
<?php 
$MysqlServer = "127.0.0.1";
$MysqlUser = "root";
$MysqlPass = "";
$MysqlDb = "vhealth";

$conn = new mysqli($MysqlServer, $MysqlUser, $MysqlPass, $MysqlDb);

if ($conn->connect_error) {
    die("<h3>Login failed, error from server</h3>");
}

$sql = sprintf(
	"SELECT id, date_time, username, data FROM %s_data", 
	$MysqlDb
);
$result = $conn->query($sql);

while($row = $result->fetch_assoc()) {
	echo("<tr>");
    echo("<td>".$row["id"]."</td>");
    echo("<td>".$row["date_time"]."</td>");
    echo("<td>".$row["username"]."</td>");
    echo("<td>".$row["data"]."</td>");
    echo("</tr>");
}

$conn->close();
?>
</table>
</body>
</html>