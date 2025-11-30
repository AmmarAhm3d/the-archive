<!DOCTYPE html>
<html>
<head>
	<title>Student Profile</title>
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
	<header class="bg-primary text-white">
		<div class="container">
			<h1>Student Profile</h1>
		</div>
	</header>
	<section class="container mt-5">
		<h2>Personal Information</h2>
		<div class="card p-3">
			<div class="card-body">
				<div class="form-group">
					<label for="name">Name:</label>
					<span class="form-control" id="name">John Doe</span>
				</div>
				<div class="form-group">
					<label for="student-id">Student ID:</label>
					<span class="form-control" id="student-id">12345</span>
				</div>
				<div class="form-group">
					<label for="email">Email:</label>
					<span class="form-control" id="email">john.doe@example.com</span>
				</div>
				<div class="form-group">
					<label for="phone">Phone:</label>
					<span class="form-control" id="phone">123-456-7890</span>
				</div>
				<div class="form-group">
					<label for="address">Address:</label>
					<span class="form-control" id="address">123 Main St, Anytown USA</span>
				</div>
			</div>
		</div>
	</section>
</body>
</html>

