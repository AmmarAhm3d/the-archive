<!DOCTYPE html>
<html>
<head>
	<title>Financial Management</title>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/bootswatch/5.3.0/quartz/bootstrap.min.css" integrity="sha512-NCzD9X02ejnv+OeOJhcQb71TgJyaNqbD1uyYyLQ2N0NOUM9NgWJHm7V/1pq/+pUn7G5U6mS06GqxFOALmIzU6w==" crossorigin="anonymous" referrerpolicy="no-referrer" />
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Quicksand" />
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">

		<style>
		/* some custom styling */
		body {
			background-color: #f2f2f2;
		}
		header {
			background-color: #343a40;
			color: white;
			padding: 1rem;
			margin-bottom: 2rem;
		}
		nav ul {
			list-style: none;
			display: flex;
			justify-content: space-between;
			align-items: center;
			padding: 0;
			margin: 0;
			background-color: #e3f2fd;
			padding: 1rem;
		}
		nav li {
			margin: 0 1rem;
		}
		nav a {
			color: #212529;
			text-decoration: none;
		}
		nav a:hover {
			color: #007bff;
			text-decoration: none;
		}
		.course-schedule table {
			width: 100%;
			border-collapse: collapse;
		}
		.course-schedule th,
		.course-schedule td {
			padding: 0.5rem;
			text-align: left;
			border-bottom: 1px solid #dee2e6;
		}
		.course-schedule th {
			background-color: #e9ecef;
			font-weight: bold;
			text-transform: uppercase;
			font-size: 0.9rem;
		}
		.course-assignments ul {
			list-style: none;
			padding: 0;
			margin: 0;
		}
		.course-assignments li {
			margin: 0.5rem 0;
		}
		.course-grades table {
			width: 100%;
			border-collapse: collapse;
		}
		.course-grades th,
		.course-grades td {
			padding: 0.5rem;
			text-align: left;
			border-bottom: 1px solid #dee2e6;
		}
		.course-grades th {
			background-color: #e9ecef;
			font-weight: bold;
			text-transform: uppercase;
			font-size: 0.9rem;
		}
	</style>
</head>
<body>
	<header>
		<h1>Financial Management</h1>
	</header>

	<nav>
		<ul>
			<li><a href="#">Home</a></li>
			<li><a href="#">Students</a></li>
			<li><a href="#">Courses</a></li>
			<li><a href="#">Enrollment</a></li>
			<li><a href="#">Financials</a></li>
			<li><a href="#">Settings</a></li>
			<li><a href="#">Logout</a></li>
		</ul>
	</nav>

	<main>
		<h2>Account Balance</h2>
		<p>Your current account balance is $500.</p>

		<h2>Tuition Fees</h2>
		<table>
			<thead>
				<tr>
					<th>Course</th>
					<th>Fee</th>
					<th>Status</th>
				</tr>
			</thead>
			<tbody>
				<tr>
					<td>English 101</td>
					<td>$500</td>
					<td>Paid</td>
				</tr>
				<tr>
					<td>Math 201</td>
					<td>$750</td>
					<td>Unpaid</td>
				</tr>
				<tr>
					<td>Science 301</td>
					<td>$600</td>
					<td>Unpaid</td>
				</tr>
			</tbody>
		</table>

		<h2>Scholarships</h2>
		<p>You have been awarded a $250 scholarship for maintaining a GPA of 3.5 or higher.</p>

		<h2>Expenses</h2>
		<ul>
			<li>Textbooks: $150</li>
			<li>Lab Fees: $75</li>
			<li>Parking Permit: $50</li>
		</ul>
	</main>

	<footer>
		<p>&copy; 2023 My School Name</p>
	</footer>
</body>
</html>
