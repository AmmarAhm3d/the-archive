<!DOCTYPE html>
<html>
<head>
	<title>Exam Management</title>
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
		<h1>Exam Management System</h1>
		<!-- add navigation links here -->
	</header>
	<main>
		<section>
			<h2>Create Exam</h2>
			<form>
				<label for="exam-title">Exam Title:</label>
				<input type="text" id="exam-title" name="exam-title" required>
				<label for="exam-date">Exam Date:</label>
				<input type="date" id="exam-date" name="exam-date" required>
				<label for="exam-time">Exam Time:</label>
				<input type="time" id="exam-time" name="exam-time" required>
				<!-- add more form elements as needed -->
				<input type="submit" value="Create Exam">
			</form>
		</section>
		<section>
			<h2>Distribute Exam</h2>
			<form>
				<label for="exam-id">Exam ID:</label>
				<input type="text" id="exam-id" name="exam-id" required>
				<label for="class-id">Class ID:</label>
				<input type="text" id="class-id" name="class-id" required>
				<label for="exam-file">Exam File:</label>
				<input type="file" id="exam-file" name="exam-file" accept=".pdf">
				<!-- add more form elements as needed -->
				<input type="submit" value="Distribute Exam">
			</form>
		</section>
		<section>
			<h2>Grade Exam</h2>
			<form>
				<label for="exam-id">Exam ID:</label>
				<input type="text" id="exam-id" name="exam-id" required>
				<label for="student-id">Student ID:</label>
				<input type="text" id="student-id" name="student-id" required>
				<label for="exam-grade">Exam Grade:</label>
				<input type="number" id="exam-grade" name="exam-grade" min="0" max="100" required>
				<!-- add more form elements as needed -->
				<input type="submit" value="Grade Exam">
			</form>
		</section>
	</main>
	<footer>
		<p>&copy; 2023 Exam Management System</p>
	</footer>
</body>
</html>