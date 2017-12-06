graph
[
	node
	[
		id 140213280057712
		label "PLUS"
	]

	node
	[
		id 140213280057760
		label "2"
	]

	edge
	[
		source 140213280057712
		target 140213280057760
		label "left"
	]
	node
	[
		id 140213282144256
		label "MULTIPLY"
	]

	node
	[
		id 140213280058144
		label "2"
	]

	edge
	[
		source 140213282144256
		target 140213280058144
		label "left"
	]
	node
	[
		id 140213280058192
		label "POWER"
	]

	node
	[
		id 140213280058240
		label "x"
	]

	edge
	[
		source 140213280058192
		target 140213280058240
		label "left"
	]
	node
	[
		id 140213280058288
		label "1"
	]

	edge
	[
		source 140213280058192
		target 140213280058288
		label "right"
	]
	edge
	[
		source 140213282144256
		target 140213280058192
		label "right"
	]
	edge
	[
		source 140213280057712
		target 140213282144256
		label "right"
	]
]
