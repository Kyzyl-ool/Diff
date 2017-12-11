graph
[
	node
	[
		id 140328640194448
		label "DIVIDE"
	]

	node
	[
		id 140328640194496
		label "SIN"
	]

	node
	[
		id 140328640194544
		label "x"
	]

	edge
	[
		source 140328640194496
		target 140328640194544
		label "left"
	]
	edge
	[
		source 140328640194448
		target 140328640194496
		label "left"
	]
	node
	[
		id 140328640194592
		label "COS"
	]

	node
	[
		id 140328640194640
		label "x"
	]

	edge
	[
		source 140328640194592
		target 140328640194640
		label "left"
	]
	edge
	[
		source 140328640194448
		target 140328640194592
		label "right"
	]
]
