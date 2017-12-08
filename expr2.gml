graph
[
	node
	[
		id 140677723728144
		label "PLUS"
	]

	node
	[
		id 140677723728192
		label "MULTIPLY"
	]

	node
	[
		id 140677723728288
		label "MULTIPLY"
	]

	node
	[
		id 140677723728336
		label "3"
	]

	edge
	[
		source 140677723728288
		target 140677723728336
		label "left"
	]
	node
	[
		id 140677723728384
		label "POWER"
	]

	node
	[
		id 140677723728432
		label "x"
	]

	edge
	[
		source 140677723728384
		target 140677723728432
		label "left"
	]
	node
	[
		id 140677723728480
		label "2"
	]

	edge
	[
		source 140677723728384
		target 140677723728480
		label "right"
	]
	edge
	[
		source 140677723728288
		target 140677723728384
		label "right"
	]
	edge
	[
		source 140677723728192
		target 140677723728288
		label "left"
	]
	node
	[
		id 140677723728528
		label "POWER"
	]

	node
	[
		id 140677723728576
		label "x"
	]

	edge
	[
		source 140677723728528
		target 140677723728576
		label "left"
	]
	node
	[
		id 140677723728624
		label "3"
	]

	edge
	[
		source 140677723728528
		target 140677723728624
		label "right"
	]
	edge
	[
		source 140677723728192
		target 140677723728528
		label "right"
	]
	edge
	[
		source 140677723728144
		target 140677723728192
		label "left"
	]
	node
	[
		id 140677723728240
		label "MULTIPLY"
	]

	node
	[
		id 140677723728672
		label "POWER"
	]

	node
	[
		id 140677723728720
		label "x"
	]

	edge
	[
		source 140677723728672
		target 140677723728720
		label "left"
	]
	node
	[
		id 140677723728768
		label "3"
	]

	edge
	[
		source 140677723728672
		target 140677723728768
		label "right"
	]
	edge
	[
		source 140677723728240
		target 140677723728672
		label "left"
	]
	node
	[
		id 140677723728816
		label "MULTIPLY"
	]

	node
	[
		id 140677723728864
		label "3"
	]

	edge
	[
		source 140677723728816
		target 140677723728864
		label "left"
	]
	node
	[
		id 140677723728912
		label "POWER"
	]

	node
	[
		id 140677723728960
		label "x"
	]

	edge
	[
		source 140677723728912
		target 140677723728960
		label "left"
	]
	node
	[
		id 140677723729008
		label "2"
	]

	edge
	[
		source 140677723728912
		target 140677723729008
		label "right"
	]
	edge
	[
		source 140677723728816
		target 140677723728912
		label "right"
	]
	edge
	[
		source 140677723728240
		target 140677723728816
		label "right"
	]
	edge
	[
		source 140677723728144
		target 140677723728240
		label "right"
	]
]
