<?php
if($_POST){
    $n = htmlspecialchars($_POST['name']);
    $e = htmlspecialchars($_POST['email']);
    $m = htmlspecialchars($_POST['message']);

    echo "Thanks $n<br>$e<br>$m<hr>";
}
?>

<!DOCTYPE html>
<html>
<body>

<form method="POST">
<input name="name" placeholder="Name"><br>
<input name="email" placeholder="Email"><br>
<textarea name="message" placeholder="Feedback"></textarea><br>
<button>Submit</button>
</form>

</body>
</html>