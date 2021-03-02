<?php
$server="localhost";
$username="root";//THE DEFAULT USERNAME OF THE DATABASE
$password="";
$dbname="devices";
$con=mysqli_connect($server,$username,$password,$dbname) or die("unable to connect");
$rank=$_GET["DN"];
$sql="SELECT status from devices where devicename=$rank";//WE ARE TRYING TO GET THE NAME OF THE STUDENT BY ENTERING THE RANK
$result=mysqli_query($con,$sql);
if ($result->num_rows > 0) {
    
    while ($row = $result->fetch_assoc())
    {
        echo $row['status'];
    }
        
    } else {
        echo "Error:" . $sql . "<br>" . $conn->error;
    }
    
?>