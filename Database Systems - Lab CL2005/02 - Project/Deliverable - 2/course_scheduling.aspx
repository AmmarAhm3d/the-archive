<!DOCTYPE html>
<html>
<head>
	<title>Course Scheduling</title>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/bootswatch/5.3.0/quartz/bootstrap.min.css" integrity="sha512-NCzD9X02ejnv+OeOJhcQb71TgJyaNqbD1uyYyLQ2N0NOUM9NgWJHm7V/1pq/+pUn7G5U6mS06GqxFOALmIzU6w==" crossorigin="anonymous" referrerpolicy="no-referrer" />
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Quicksand" />
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">

		<link rel="stylesheet" type="text/css" href="style.css">
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
		<h1>Course Scheduling</h1>
	</header>
	<nav>
		<ul>
			<li><a href="#">Dashboard</a></li>
			<li><a href="#">Courses</a></li>
			<li><a href="#">Assignments</a></li>
			<li><a href="#">Grades</a></li>
		</ul>
	</nav>
	<main>
		<section class="course-schedule">
			<h2>Course Schedule</h2>
			<table>
				<thead>
					<tr>
						<th>Course Code</th>
						<th>Course Name</th>
						<th>Instructor</th>
						<th>Time</th>
						<th>Room</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td>CSCI101</td>
						<td>Introduction to Computer Science</td>
						
						<td>Dr. John Smith</td>
						<td>Mon/Wed/Fri 9:00-10:00am</td>
						<td>Room 101</td>
					</tr>
					<tr>
						<td>MATH201</td>
						<td>Calculus II</td>
						<td>Dr. Sarah Johnson</td>
						<td>Tue/Thu 11:00am-12:30pm</td>
						<td>Room 202</td>
					</tr>
					<!-- add more courses here -->
				</tbody>
			</table>
		</section>
		<section class="course-assignments">
			<h2>Assignments</h2>
			<ul>
				<li><a href="#">CSCI101: Assignment 1</a></li>
				<li><a href="#">MATH201: Assignment 2</a></li>
				<li><a href="#">PHYS101: Lab Report</a></li>
				<!-- add more assignments here -->
			</ul>
		</section>
		<section class="course-grades">
			<h2>Grades</h2>
			<table>
				<thead>
					<tr>
						<th>Course Code</th>
						<th>Course Name</th>
						<th>Assignment 1</th>
						<th>Assignment 2</th>
						<th>Midterm Exam</th>
						<th>Final Exam</th>
						<th>Overall Grade</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td>CSCI101</td>
						<td>Introduction to Computer Science</td>
						<td>90</td>
						<td>85</td>
						<td>80</td>
						<td>85</td>
						<td>87</td>
					</tr>
					<tr>
						<td>MATH201</td>
						<td>Calculus II</td>
						<td>95</td>
						<td>90</td>
						<td>85</td>
						<td>90</td>
						<td>90</td>
					</tr>
					<!-- add more courses here -->
				</tbody>
			</table>
		</section>

