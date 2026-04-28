<?php
session_start();

if (isset($_POST['next'])) {
    $_SESSION['n'] = $_POST['name'];
    $_SESSION['e'] = $_POST['email'];
    header("Location:?step=2");
    exit;
}

if (isset($_POST['finish'])) {
    echo "Name: ".$_SESSION['n']."<br>Email: ".$_SESSION['e']."<br>Address: ".$_POST['address'];
    session_destroy();
    exit;
}

$step = $_GET['step'] ?? 1;
?>

<!DOCTYPE html>
<html>
<body>

<form method="POST">

<?php if ($step == 1): ?>
<input name="name" placeholder="Name"><br>
<input name="email" placeholder="Email"><br>
<button name="next">Next</button>

<?php else: ?>
<input name="address" placeholder="Address"><br>
<button name="finish">Submit</button>
<?php endif; ?>

</form>

</body>
</html>