graph
[
	node
	[
		id 140508835882912
		label "DIVIDE"
	]

	node
	[
		id 140508835882960
		label "MINUS"
	]

	node
	[
		id 140508835883008
		label "POWER"
	]

	node
	[
		id 140508835883088
		label "x"
	]

	edge
	[
		source 140508835883008
		target 140508835883088
		label "left"
	]
	node
	[
		id 140508835883136
		label "2"
	]

	edge
	[
		source 140508835883008
		target 140508835883136
		label "right"
	]
	edge
	[
		source 140508835882960
		target 140508835883008
		label "left"
	]
	node
	[
		id 140508835883184
		label "1"
	]

	edge
	[
		source 140508835882960
		target 140508835883184
		label "right"
	]
	edge
	[
		source 140508835882912
		target 140508835882960
		label "left"
	]
	node
	[
		id 140508835883232
		label "x"
	]

	edge
	[
		source 140508835882912
		target 140508835883232
		label "right"
	]
]
