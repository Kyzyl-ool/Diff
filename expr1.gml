graph
[
	node
	[
		id 140362110740384
		label "DIVIDE"
	]

	node
	[
		id 140362110740432
		label "PLUS"
	]

	node
	[
		id 140362110740480
		label "POWER"
	]

	node
	[
		id 140362110740560
		label "x"
	]

	edge
	[
		source 140362110740480
		target 140362110740560
		label "left"
	]
	node
	[
		id 140362110740608
		label "2"
	]

	edge
	[
		source 140362110740480
		target 140362110740608
		label "right"
	]
	edge
	[
		source 140362110740432
		target 140362110740480
		label "left"
	]
	node
	[
		id 140362110740656
		label "1"
	]

	edge
	[
		source 140362110740432
		target 140362110740656
		label "right"
	]
	edge
	[
		source 140362110740384
		target 140362110740432
		label "left"
	]
	node
	[
		id 140362110740704
		label "x"
	]

	edge
	[
		source 140362110740384
		target 140362110740704
		label "right"
	]
]
