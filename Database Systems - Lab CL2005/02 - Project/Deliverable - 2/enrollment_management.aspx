<!DOCTYPE html>
<html>
<head>
	<title>Enrollment Management</title>
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
		<nav>
			<ul>
				<li><a href="#">Home</a></li>
				<li><a href="#">About Us</a></li>
				<li><a href="#">Contact Us</a></li>
			</ul>
		</nav>
		<h1>Enrollment Management</h1>

	</header>
	<section>
	<h2>New Student Enrollment</h2>
	<form>
		<label for="student-name">Student Name:</label>
		<input type="text" id="student-name" name="student-name">
		<label for="student-id">Student ID:</label>
		<input type="text" id="student-id" name="student-id">
		<label for="email">Email:</label>
		<input type="email" id="email" name="email">
		<label for="phone">Phone Number:</label>
		<input type="tel" id="phone" name="phone">
		<label for="address">Address:</label>
		<textarea id="address" name="address"></textarea>
		<label for="registration-fee">Registration Fee:</label>
		<input type="number" id="registration-fee" name="registration-fee">
		<input type="submit" value="Enroll">
	</form>
</section>

<footer>
	<p>&copy; 2023 Enrollment Management System</p>
</footer>

	</body>
</html>
