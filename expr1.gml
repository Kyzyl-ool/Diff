graph
[
	node
	[
		id 140213280057248
		label "PLUS"
	]

	node
	[
		id 140213280057296
		label "PLUS"
	]

	node
	[
		id 140213280057344
		label "MULTIPLY"
	]

	node
	[
		id 140213280057424
		label "2"
	]

	edge
	[
		source 140213280057344
		target 140213280057424
		label "left"
	]
	node
	[
		id 140213280057472
		label "x"
	]

	edge
	[
		source 140213280057344
		target 140213280057472
		label "right"
	]
	edge
	[
		source 140213280057296
		target 140213280057344
		label "left"
	]
	node
	[
		id 140213280057520
		label "1"
	]

	edge
	[
		source 140213280057296
		target 140213280057520
		label "right"
	]
	edge
	[
		source 140213280057248
		target 140213280057296
		label "left"
	]
	node
	[
		id 140213280057568
		label "POWER"
	]

	node
	[
		id 140213280057616
		label "x"
	]

	edge
	[
		source 140213280057568
		target 140213280057616
		label "left"
	]
	node
	[
		id 140213280057664
		label "2"
	]

	edge
	[
		source 140213280057568
		target 140213280057664
		label "right"
	]
	edge
	[
		source 140213280057248
		target 140213280057568
		label "right"
	]
]
