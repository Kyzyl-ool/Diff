graph
[
	node
	[
		id 140314002073552
		label "DIVIDE"
	]

	node
	[
		id 140314002073600
		label "MINUS"
	]

	node
	[
		id 140314002073648
		label "POWER"
	]

	node
	[
		id 140314002073696
		label "x"
	]

	edge
	[
		source 140314002073648
		target 140314002073696
		label "left"
	]
	node
	[
		id 140314002073744
		label "2"
	]

	edge
	[
		source 140314002073648
		target 140314002073744
		label "right"
	]
	edge
	[
		source 140314002073600
		target 140314002073648
		label "left"
	]
	node
	[
		id 140314002073792
		label "1"
	]

	edge
	[
		source 140314002073600
		target 140314002073792
		label "right"
	]
	edge
	[
		source 140314002073552
		target 140314002073600
		label "left"
	]
	node
	[
		id 140314002073840
		label "x"
	]

	edge
	[
		source 140314002073552
		target 140314002073840
		label "right"
	]
]
