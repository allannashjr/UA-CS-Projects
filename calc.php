<html>
	<head>
		<title>Allan's PHP Calculator</title>
		<style>
			body {
				background-color:darkorange;
				font-family:verdana;
				font-size:50px;
				text-align:center;
			}
		</style>
		<h1 style="text-align:center;">Allan's PHP Calculator</h1>
	</head>
	<body>
		<form style="text-align:center;" action="http://localhost/isp/pa2/calc.php" id="myForm" method="post">
			<input type="number" name="numA">
			<input type="number" name="numB">
			<input type="submit" name="operation" value="+">
			<input type="submit" name="operation" value="-">
			<input type="submit" name="operation" value="*">
			<input type="submit" name="operation" value="/">
			<input type="submit" name="operation" value="%">
		</form>
		
		Answer: 
		<?php
			if (isset($_POST['operation'])) {
				$a = $_POST['numA'];
				$b = $_POST['numB'];
				$op = $_POST['operation'];
				
				if($op == "+") {
					echo "${a} ${op} ${b} = ";
					echo $a + $b;
				}
				else if($op == "-") {
					echo "${a} ${op} ${b} = ";
					echo $a - $b;
				}
				else if($op == "*") {
					echo "${a} ${op} ${b} = ";
					echo $a * $b;
				}
				else if($op == "/") {
					echo "${a} ${op} ${b} = ";
					echo $a / $b;
				}
				else if($op == "%") {
					echo "${a} ${op} ${b} = ";
					echo $a % $b;
				}
			}
			else {
				echo "Please input your nuumber";
			}
		?>
	</body>
</html>