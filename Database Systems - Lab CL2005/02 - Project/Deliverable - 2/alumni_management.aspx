<!DOCTYPE html>
<html>
<head>
	<title>Alumni Management</title>
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
		<nav class="navbar navbar-expand-lg navbar-light bg-light">
			<a class="navbar-brand" href="#">My School</a>
			<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
				<span class="navbar-toggler-icon"></span>
			</button>
			<div class="collapse navbar-collapse" id="navbarNav">
				<ul class="navbar-nav">
					<li class="nav-item active">
						<a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="#">Alumni Directory</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="#">Events</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="#">Contact Us</a>
					</li>
				</ul>
			</div>
		</nav>
	</header>

	<main>
		<section class="hero">
			<div class="container">
				<h1>Welcome to the Alumni Management System</h1>
				<p>Stay connected with your alma mater and fellow alumni!</p>
			</div>
		</section>

		<section class="search">
			<div class="container">
				<h2>Alumni Directory</h2>
				<form>
					<div class="form-group">
						<label for="search-input">Search alumni by name or class year</label>
						<input type="text" class="form-control" id="search-input" placeholder="Enter search term">
					</div>
					<button type="submit" class="btn btn-primary">Search</button>
				</form>
				<p>Showing 10 out of 5000 results</p>
				<ul class="list-group">
					<li class="list-group-item">
						<h3>John Doe</h3>
						<p>Class of 2010</p>
						<p>Current Job: Software Developer at XYZ Company</p>
					</li>
					<li class="list-group-item">
						<h3>Jane Smith</h3>
						<p>Class of 2005</p>
						<p>Current Job: Marketing Manager at ABC Inc.</p>
					</li>
					<!-- more alumni profiles here -->
				</ul>
			</div>
		</section>

		<section class="events">
			<div class="container">
				<h2>Upcoming Events</h2>
				<ul class="list-group">
					<li class="list-group-item">
						<h3>Alumni Homecoming</h3>
						<p>October 15, 2023</p>
						<p>Location: School Auditorium</p>
						<p>RSVP by October 1, 2023</p>
					</li>
					<li class="list-group-item">
					<h3>Networking Night</h3>
					<p>November 10, 2023</p>
					<p>Location: Downtown Conference Center</p>
					<p>RSVP by November 1, 2023</p>
				</li>
				<!-- more events here -->
			</ul>
		</section>
	</main>

	<footer>
		<p>&copy; 2023 My School. All rights reserved.</p>
	</footer>
</body>
</html>
