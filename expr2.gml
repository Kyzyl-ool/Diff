graph
[
	node
	[
		id 140439436929248
		label "DIVIDE"
	]

	node
	[
		id 140439436929296
		label "MINUS"
	]

	node
	[
		id 140439436929392
		label "MULTIPLY"
	]

	node
	[
		id 140439436929776
		label "COS"
	]

	node
	[
		id 140439439015936
		label "x"
	]

	edge
	[
		source 140439436929776
		target 140439439015936
		label "left"
	]
	edge
	[
		source 140439436929392
		target 140439436929776
		label "left"
	]
	node
	[
		id 140439436929824
		label "COS"
	]

	node
	[
		id 140439436929872
		label "x"
	]

	edge
	[
		source 140439436929824
		target 140439436929872
		label "left"
	]
	edge
	[
		source 140439436929392
		target 140439436929824
		label "right"
	]
	edge
	[
		source 140439436929296
		target 140439436929392
		label "left"
	]
	node
	[
		id 140439436929440
		label "MULTIPLY"
	]

	node
	[
		id 140439436929920
		label "SIN"
	]

	node
	[
		id 140439436929968
		label "x"
	]

	edge
	[
		source 140439436929920
		target 140439436929968
		label "left"
	]
	edge
	[
		source 140439436929440
		target 140439436929920
		label "left"
	]
	node
	[
		id 140439440064512
		label "MULTIPLY"
	]

	node
	[
		id 140439440064560
		label "-1"
	]

	edge
	[
		source 140439440064512
		target 140439440064560
		label "left"
	]
	node
	[
		id 140439440064608
		label "SIN"
	]

	node
	[
		id 140439440064656
		label "x"
	]

	edge
	[
		source 140439440064608
		target 140439440064656
		label "left"
	]
	edge
	[
		source 140439440064512
		target 140439440064608
		label "right"
	]
	edge
	[
		source 140439436929440
		target 140439440064512
		label "right"
	]
	edge
	[
		source 140439436929296
		target 140439436929440
		label "right"
	]
	edge
	[
		source 140439436929248
		target 140439436929296
		label "left"
	]
	node
	[
		id 140439436929344
		label "POWER"
	]

	node
	[
		id 140439436929488
		label "COS"
	]

	node
	[
		id 140439436929536
		label "x"
	]

	edge
	[
		source 140439436929488
		target 140439436929536
		label "left"
	]
	edge
	[
		source 140439436929344
		target 140439436929488
		label "left"
	]
	node
	[
		id 140439436929584
		label "2"
	]

	edge
	[
		source 140439436929344
		target 140439436929584
		label "right"
	]
	edge
	[
		source 140439436929248
		target 140439436929344
		label "right"
	]
]
