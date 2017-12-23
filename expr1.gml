graph
[
	node
	[
		id 140473503066080
		label "PLUS"
	]

	node
	[
		id 140473503066128
		label "MINUS"
	]

	node
	[
		id 140473503066176
		label "PLUS"
	]

	node
	[
		id 140473503066256
		label "SIN"
	]

	node
	[
		id 140473503066304
		label "DIVIDE"
	]

	node
	[
		id 140473503066352
		label "PLUS"
	]

	node
	[
		id 140473503066400
		label "x"
	]

	edge
	[
		source 140473503066352
		target 140473503066400
		label "left"
	]
	node
	[
		id 140473503066448
		label "1"
	]

	edge
	[
		source 140473503066352
		target 140473503066448
		label "right"
	]
	edge
	[
		source 140473503066304
		target 140473503066352
		label "left"
	]
	node
	[
		id 140473503066496
		label "2"
	]

	edge
	[
		source 140473503066304
		target 140473503066496
		label "right"
	]
	edge
	[
		source 140473503066256
		target 140473503066304
		label "left"
	]
	edge
	[
		source 140473503066176
		target 140473503066256
		label "left"
	]
	node
	[
		id 140473503066544
		label "1"
	]

	edge
	[
		source 140473503066176
		target 140473503066544
		label "right"
	]
	edge
	[
		source 140473503066128
		target 140473503066176
		label "left"
	]
	node
	[
		id 140473503066592
		label "x"
	]

	edge
	[
		source 140473503066128
		target 140473503066592
		label "right"
	]
	edge
	[
		source 140473503066080
		target 140473503066128
		label "left"
	]
	node
	[
		id 140473503066640
		label "POWER"
	]

	node
	[
		id 140473503066688
		label "x"
	]

	edge
	[
		source 140473503066640
		target 140473503066688
		label "left"
	]
	node
	[
		id 140473503066736
		label "2"
	]

	edge
	[
		source 140473503066640
		target 140473503066736
		label "right"
	]
	edge
	[
		source 140473503066080
		target 140473503066640
		label "right"
	]
]
