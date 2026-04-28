<!DOCTYPE html>
<html>
<body>

<form method="GET">
<input name="k" placeholder="Search course">
<button>Search</button>
</form>

<?php
if(isset($_GET['k'])){
    $k = htmlspecialchars($_GET['k']);
    echo "Results for: $k";
}
?>

</body>
</html>