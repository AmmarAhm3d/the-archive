<!DOCTYPE html>
<html>
<head>
	<title>Student Performance Analysis</title>
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
		<h1>Student Performance Analysis</h1>
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="style.css">
		<nav>
			<ul>
				<li><a href="#">Dashboard</a></li>
				<li><a href="#">Reports</a></li>
				<li><a href="#">Analytics</a></li>
			</ul>
		</nav>
	</header>
	<main>
		<section class="overview">
			<h2>Performance Overview</h2>
			<p>Here's an overview of how the students in your class are performing:</p>
			<ul>
				<li><strong>Class Average:</strong> 85%</li>
				<li><strong>Highest Grade:</strong> 98%</li>
				<li><strong>Lowest Grade:</strong> 70%</li>
			</ul>
		</section>
		<section class="charts">
			<h2>Performance Charts</h2>
			<p>Here are some charts and graphs to help you visualize student performance:</p>
			<div class="chart-container">
				<!-- Insert chart code here -->
			</div>
		</section>
		<section class="feedback">
			<h2>Student Feedback</h2>
			<p>Provide personalized feedback to students to help them improve:</p>
			<form>
				<label for="student-select">Select a student:</label>
				<select id="student-select" name="student">
					<option value="john-doe">John Doe</option>
					<option value="jane-doe">Jane Doe</option>
					<option value="bob-smith">Bob Smith</option>
				</select>
				<label for="feedback-textarea">Provide feedback:</label>
				<textarea id="feedback-textarea" name="feedback"></textarea>
				<button type="submit">Submit Feedback</button>
			</form>
		</section>
	</main>
	<footer>
		<p>&copy; 2023 Student Management System</p>
	</footer>
</body>
</html>
