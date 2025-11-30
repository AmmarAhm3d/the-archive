<!DOCTYPE html>
<html>
<head>
	<title>Attendance Management</title>
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
	<header><h1>Attendance Management</h1></header>
	<div class="container">
		<div class="row">
			<div class="col-md-6">
				<h2>Take Attendance</h2>
				<form>
					<div class="form-group">
						<label for="class">Class:</label>
						<select id="class" name="class" class="form-control">
							<option value="">Select Class</option>
							<option value="class1">Class 1</option>
							<option value="class2">Class 2</option>
							<option value="class3">Class 3</option>
						</select>
					</div>
					<div class="form-group">
						<label for="date">Date:</label>
						<input type="date" id="date" name="date" class="form-control">
					</div>
					<table class="table">
						<thead>
							<tr>
								<th>Student Name</th>
								<th>Roll Number</th>
								<th>Present</th>
							</tr>
						</thead>
						<tbody>
							<tr>
								<td>John Doe</td>
								<td>1</td>
								<td><input type="checkbox" name="present[]"></td>
							</tr>
							<tr>
								<td>Jane Doe</td>
								<td>2</td>
								<td><input type="checkbox" name="present[]"></td>
							</tr>
							<tr>
								<td>Bob Smith</td>
								<td>3</td>
								<td><input type="checkbox" name="present[]"></td>
							</tr>
						</tbody>
					</table>
					<input type="submit" value="Submit" class="btn btn-primary">
				</form>
			</div>
			<div class="col-md-6">
				<h2>Attendance Reports</h2>
				<p>Select a class and a date to view the attendance report:</p>
				<form>
					<div class="form-group">
						<label for="class">Class:</label>
						<select id="class" name="class" class="form-control">
							<option value="">Select Class</option>
							<option value="class1">Class 1</option>
							<option value="class2">Class 2</option>
							<option value="class3">Class 3</option>
						</select>
					</div>
					<div class="form-group">
						<label for="date">Date:</label>
						<input type="date" id="date" name="date" class="form-control">
					</div>
					<input type="submit" value="View Report" class="btn btn-primary">
				</form>
			</div>
		</div>
	</div>
</body>
</html>
