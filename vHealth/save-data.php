<?php 
$MysqlServer = "127.0.0.1";
$MysqlUser = "root";
$MysqlPass = "";
$MysqlDb = "vhealth";

$conn = new mysqli($MysqlServer, $MysqlUser, $MysqlPass, $MysqlDb);

if ($conn->connect_error) {
    die("no");
}
if (!isset($_POST["username"]) || !isset($_POST["data"]))
	die("no");

$sql = sprintf(
	"INSERT INTO %s_data(date_time, username, data) VALUES('%s', '%s', '%s')",
	$MysqlDb,
	date('m/d/Y h:i:s a', time()),
	$_POST["username"],
	$_POST["data"]
);
if ($conn->query($sql) === TRUE){
	$conn->close();
	die("yes");
}
else{
	$conn->close();
	die("no");
}
?>