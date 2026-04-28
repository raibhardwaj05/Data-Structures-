<?php
header('Content-Type: application/json');

$data = json_decode(file_get_contents('php://input'), true);

if ($data['email']=="test@sies.edu" && $data['password']=="12345")
    echo json_encode(["status"=>"success","message"=>"Login Success"]);
else
    echo json_encode(["status"=>"error","message"=>"Invalid"]);
?>