graph
[
	node
	[
		id 140222465583056
		label "DIVIDE"
	]

	node
	[
		id 140222465583104
		label "MINUS"
	]

	node
	[
		id 140222465583152
		label "POWER"
	]

	node
	[
		id 140222465583200
		label "x"
	]

	edge
	[
		source 140222465583152
		target 140222465583200
		label "left"
	]
	node
	[
		id 140222465583248
		label "2"
	]

	edge
	[
		source 140222465583152
		target 140222465583248
		label "right"
	]
	edge
	[
		source 140222465583104
		target 140222465583152
		label "left"
	]
	node
	[
		id 140222465583296
		label "1"
	]

	edge
	[
		source 140222465583104
		target 140222465583296
		label "right"
	]
	edge
	[
		source 140222465583056
		target 140222465583104
		label "left"
	]
	node
	[
		id 140222465583344
		label "x"
	]

	edge
	[
		source 140222465583056
		target 140222465583344
		label "right"
	]
]
