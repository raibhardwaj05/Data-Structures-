<?php
$conn = new mysqli("localhost", "root", "", "InventoryDB");

// ADD
if (isset($_POST['add'])) {
    $n = $_POST['name']; $p = $_POST['price']; $q = $_POST['quantity'];
    $conn->query("INSERT INTO products (name, price, quantity) VALUES ('$n','$p','$q')");
}

// DELETE
if (isset($_GET['del'])) {
    $conn->query("DELETE FROM products WHERE id=".$_GET['del']);
}

// UPDATE
if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $conn->query("UPDATE products SET price=".$_POST['price']." WHERE id=$id");
}

$res = $conn->query("SELECT * FROM products");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Inventory</title>
</head>
<body>

<h2>Product Inventory</h2>

<form method="POST">
    <input type="text" name="name" placeholder="Name" required>
    <input type="number" step="0.01" name="price" placeholder="Price" required>
    <input type="number" name="quantity" placeholder="Qty" required>
    <button type="submit" name="add">Add</button>
</form>

<br>

<table border="1">
<tr>
    <th>ID</th><th>Name</th><th>Price</th><th>Qty</th><th>Action</th>
</tr>

<?php while($row = $result->fetch_assoc()): ?>
<tr>
    <td><?= $row['id'] ?></td>
    <td><?= $row['name'] ?></td>
    <td><?= $row['price'] ?></td>
    <td><?= $row['quantity'] ?></td>
    <td><a href="?delete=<?= $row['id'] ?>">Delete</a></td>
</tr>
<?php endwhile; ?>

</table>

</body>
</html>