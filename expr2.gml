graph
[
	node
	[
		id 140732561096704
		label "DIVIDE"
	]

	node
	[
		id 140732561096752
		label "MINUS"
	]

	node
	[
		id 140732561096848
		label "MULTIPLY"
	]

	node
	[
		id 140732561097184
		label "1"
	]

	edge
	[
		source 140732561096848
		target 140732561097184
		label "left"
	]
	node
	[
		id 140732561097232
		label "x"
	]

	edge
	[
		source 140732561096848
		target 140732561097232
		label "right"
	]
	edge
	[
		source 140732561096752
		target 140732561096848
		label "left"
	]
	node
	[
		id 140732561096896
		label "MULTIPLY"
	]

	node
	[
		id 140732561097376
		label "x"
	]

	edge
	[
		source 140732561096896
		target 140732561097376
		label "left"
	]
	node
	[
		id 140732561097424
		label "1"
	]

	edge
	[
		source 140732561096896
		target 140732561097424
		label "right"
	]
	edge
	[
		source 140732561096752
		target 140732561096896
		label "right"
	]
	edge
	[
		source 140732561096704
		target 140732561096752
		label "left"
	]
	node
	[
		id 140732561096800
		label "POWER"
	]

	node
	[
		id 140732561096992
		label "x"
	]

	edge
	[
		source 140732561096800
		target 140732561096992
		label "left"
	]
	node
	[
		id 140732561097040
		label "2"
	]

	edge
	[
		source 140732561096800
		target 140732561097040
		label "right"
	]
	edge
	[
		source 140732561096704
		target 140732561096800
		label "right"
	]
]
