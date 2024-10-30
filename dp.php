<?php 
$servername = "localhost"; 
$username = "root";
$password = "";
$dbname = "user";
$conn = new mysqli($servername, $username, $password, $dbname); 
$username = $_POST['username']; 
$password = $_POST['password']; 
$sql = "INSERT INTO users (username, password) VALUES ('$username', '$password')"; 
if ($conn->query($sql) === TRUE) { 
    echo "Registration successful!"."<br>"; 
} else { 
    echo "Error in insertion"; 
}
$deleteUsername = $_POST['delete_username'];
$sql1 = "DELETE FROM users WHERE username='$deleteUsername'";
if ($conn->query($sql1) === TRUE) { 
    echo "User deleted successfully!";
} else { 
    echo "Error deleting user: " . $conn->error;
}
$currentUsername = $_POST['current_username'];
$newUsername = $_POST['new_username'];
$sql3 = "UPDATE users SET username='$newUsername' WHERE username='$currentUsername'";
if ($conn->query($sql3) === TRUE) { 
    echo "Username updated successfully!";
} else { 
    echo "Error updating username: " . $conn->error;
}
$conn->close();
?>
