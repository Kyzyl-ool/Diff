graph
[
	node
	[
		id 140383359084704
		label "MULTIPLY"
	]

	node
	[
		id 140383359084944
		label "3"
	]

	edge
	[
		source 140383359084704
		target 140383359084944
		label "left"
	]
	node
	[
		id 140383359084992
		label "POWER"
	]

	node
	[
		id 140383359085088
		label "MINUS"
	]

	node
	[
		id 140383359085136
		label "x"
	]

	edge
	[
		source 140383359085088
		target 140383359085136
		label "left"
	]
	node
	[
		id 140383359085184
		label "2"
	]

	edge
	[
		source 140383359085088
		target 140383359085184
		label "right"
	]
	edge
	[
		source 140383359084992
		target 140383359085088
		label "left"
	]
	node
	[
		id 140383359085232
		label "MINUS"
	]

	node
	[
		id 140383359085328
		label "3"
	]

	edge
	[
		source 140383359085232
		target 140383359085328
		label "left"
	]
	node
	[
		id 140383359085376
		label "1"
	]

	edge
	[
		source 140383359085232
		target 140383359085376
		label "right"
	]
	edge
	[
		source 140383359084992
		target 140383359085232
		label "right"
	]
	edge
	[
		source 140383359084704
		target 140383359084992
		label "right"
	]
]
