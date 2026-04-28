<?php
$conn = new mysqli("localhost", "root", "", "ShopDB");

if (isset($_POST['add'])) {
    $n=$_POST['name']; $p=$_POST['price']; $q=$_POST['qty'];
    $conn->query("INSERT INTO inventory VALUES(NULL,'$n','$p','$q')");
}

if (isset($_GET['del'])) {
    $conn->query("DELETE FROM inventory WHERE id=".$_GET['del']);
}

$data = $conn->query("SELECT * FROM inventory");
?>

<!DOCTYPE html>
<html>
<body style="font-family: Arial; padding: 20px;">
    <h2>Retail Inventory Management</h2>
    <form method="POST" style="margin-bottom: 20px;">
        <input type="text" name="name" placeholder="Item Name" required>
        <input type="number" step="0.01" name="price" placeholder="Price" required>
        <input type="number" name="qty" placeholder="Stock" required>
        <button name="add">Add Product</button>
    </form>

    <table border="1" cellpadding="10" style="width: 100%; border-collapse: collapse;">
        <tr><th>ID</th><th>Name</th><th>Price</th><th>Stock</th><th>Action</th></tr>
        <?php while($row = $items->fetch_assoc()): ?>
        <tr>
            <td><?php echo $row['id']; ?></td>
            <td><?php echo $row['name']; ?></td>
            <td><?php echo $row['price']; ?></td>
            <td><?php echo $row['quantity']; ?></td>
            <td><a href="?del=<?php echo $row['id']; ?>">Delete</a></td>
        </tr>
        <?php endwhile; ?>
    </table>
</body>
</html>