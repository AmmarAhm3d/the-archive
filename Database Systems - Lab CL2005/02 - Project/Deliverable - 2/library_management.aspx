<!DOCTYPE html>
<html>
<head>
	<title>Library Management</title>
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
		.form-container {
			background-color: white;
			padding: 2rem;
			border-radius: 5px;
			box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
			max-width: 600px;
			margin: 0 auto;
		}
		.form-group {
			margin-bottom: 1.5rem;
		}
		label {
			font-weight: bold;
			display: block;
			margin-bottom: 0.5rem;
		}
		input[type="text"],
		input[type="email"],
		input[type="password"],
		select,
		textarea {
			width: 100%;
			padding: 0.5rem;
			border: 1px solid #ced4da;
			border-radius: 3px;
			background-color: #f8f9fa;
		}
		button[type="submit"] {
			background-color: #007bff;
			color: white;
			border: none;
			border-radius: 3px;
			padding: 0.5rem 1rem;
			cursor: pointer;
			transition: background-color 0.2s ease;
		}
		button[type="submit"]:hover {
			background-color: #0069d9;
		}
	</style>
</head>
<body>
	<header>
		<h1>Library Management</h1>
	</header>
	<div class="container">
		<div class="form-container">
			<h2>Add a New Resource</h2>
			<form action="" method="POST">
				<div class="form-group">
					<label for="title">Title</label>
					<input type="text" id="title" name="title" required>
				</div>
				<div class="form-group">
					<label for="author">Author</label>
					<input type="text" id="author" name="author" required>
				</div>
				<div class="form-group">
					<label for="subject">Subject</label>
					<input type="text" id="subject" name="subject" required>
				</div>
				<div class="form-group">
					<label for="type">Type</label>
					<select id="type" name="type" required>
						<option value="">--Select--</option>
						<option value="Book">Book</option>
						<option value="Magazine">Magazine</option>
						<option value="Newspaper">Newspaper</option>
						<option value="Journal">Journal</option>
					</select>
				</div>
				<div class="form-group">
					<label for="description">Description</label>
					<textarea id="description" name="description" rows="5" required></textarea>
				</div>
				<div class="form-group">
					<label for="status">Status</label>
					<select id="status" name="status" required>
						<option value="">--Select--</option>
						<option value="Available">Available</option>
						<option value="Not Available">Not Available</option>
					</select>
				</div>
				<button type="submit" class="btn btn-primary">Submit</button>
			</form>
		</div>
		<div class="search-container">
			<h2>Access Library Resources</h2>
			<form action="" method="POST">
				<div class="form-group">
					<label for="teacher">Select Teacher:</label>
					<select name="teacher" id="teacher">
						<option value="">--Select--</option>
						<option value="teacher1">Teacher 1</option>
						<option value="teacher2">Teacher 2</option>
						<option value="teacher3">Teacher 3</option>
					</select>
				</div>
				<div class="form-group">
					<label for="resource-type">Select Resource Type:</label>
					<select name="resource-type" id="resource-type">
						<option value="">--Select--</option>
						<option value="book">Book</option>
						<option value="magazine">Magazine</option>
						<option value="journal">Journal</option>
					</select>
				</div>
				<div class="form-group">
					<label for="resource-title">Resource Title:</label>
					<input type="text" id="resource-title" name="resource-title">
				</div>
				<div class="form-group">
					<button type="submit" class="btn btn-primary">Search Resources</button>
				</div>
			</form>
			<h2>Search Results</h2>
			<div class="search-results">
				<table class="table table-striped">
					<thead>
						<tr>
							
						<th>Resource Type</th>
						<th>Title</th>
						<th>Author</th>
						<th>Publication Date</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td>Book</td>
						<td>Harry Potter and the Sorcerer's Stone</td>
						<td>J.K. Rowling</td>
						<td>1997</td>
					</tr>
					<tr>
						<td>Magazine</td>
						<td>National Geographic</td>
						<td>National Geographic Society</td>
						<td>1888</td>
					</tr>
					<tr>
						<td>Journal</td>
						<td>Nature</td>
						<td>Various</td>
						<td>1869</td>
					</tr>
				</tbody>
			</table>
		</div>
	</div>
</body>

</html>