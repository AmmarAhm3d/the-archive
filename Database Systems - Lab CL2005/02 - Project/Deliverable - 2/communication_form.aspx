<!DOCTYPE html>
<html>
<head>
	<title>Academic Records - Communication Form</title>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/bootswatch/5.3.0/quartz/bootstrap.min.css" integrity="sha512-NCzD9X02ejnv+OeOJhcQb71TgJyaNqbD1uyYyLQ2N0NOUM9NgWJHm7V/1pq/+pUn7G5U6mS06GqxFOALmIzU6w==" crossorigin="anonymous" referrerpolicy="no-referrer" />
	<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Quicksand" />
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="style.css">
	<style>
		body {
			background-color: #f2f2f2;
		}
		header {
			background-color: #343a40;
			color: white;
			padding: 1rem;
			margin-bottom: 2rem;
		}
		form {
			background-color: white;
			padding: 1rem;
			border-radius: 5px;
			box-shadow: 0px 0px 5px 0px rgba(0,0,0,0.2);
		}
		input[type="text"], textarea {
			width: 100%;
			padding: 0.5rem;
			border-radius: 5px;
			border: 1px solid #ccc;
			margin-bottom: 1rem;
			font-size: 1rem;
		}
		select {
			width: 100%;
			padding: 0.5rem;
			border-radius: 5px;
			border: 1px solid #ccc;
			margin-bottom: 1rem;
			font-size: 1rem;
		}
		button[type="submit"] {
			background-color: #007bff;
			color: white;
			padding: 0.5rem;
			border: none;
			border-radius: 5px;
			cursor: pointer;
			font-size: 1rem;
		}
		button[type="submit"]:hover {
			background-color: #0069d9;
		}
	</style>
</head>
<body>
	<header>
		<h1>Academic Records</h1>
	</header>
	<div class="container">
		<form>
			<h2>Communication Form</h2>
			<label for="subject">Subject:</label>
			<input type="text" id="subject" name="subject" required>
			<label for="message">Message:</label>
			<textarea id="message" name="message" required></textarea>
			<label for="recipient-type">Recipient Type:</label>
			<select id="recipient-type" name="recipient-type" required>
				<option value="">Select Recipient Type</option>
				<option value="student">Student</option>
				<option value="parent">Parent</option>
				<option value="teacher">Teacher</option>
			</select>
			<label for="recipient-email">Recipient Email:</label>
			<input type="text" id="recipient-email" name="recipient-email" required>
			<button type="submit">Send</button>
		</form>
	</div>
</body>
</html>