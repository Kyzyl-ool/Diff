graph
[
	node
	[
		id 140488946493408
		label "POWER"
	]

	node
	[
		id 140488946493456
		label "PLUS"
	]

	node
	[
		id 140488946493504
		label "PLUS"
	]

	node
	[
		id 140488946493584
		label "SIN"
	]

	node
	[
		id 140488946493632
		label "x"
	]

	edge
	[
		source 140488946493584
		target 140488946493632
		label "left"
	]
	edge
	[
		source 140488946493504
		target 140488946493584
		label "left"
	]
	node
	[
		id 140488946493680
		label "TAN"
	]

	node
	[
		id 140488946493728
		label "x"
	]

	edge
	[
		source 140488946493680
		target 140488946493728
		label "left"
	]
	edge
	[
		source 140488946493504
		target 140488946493680
		label "right"
	]
	edge
	[
		source 140488946493456
		target 140488946493504
		label "left"
	]
	node
	[
		id 140488946493776
		label "MULTIPLY"
	]

	node
	[
		id 140488946493824
		label "3"
	]

	edge
	[
		source 140488946493776
		target 140488946493824
		label "left"
	]
	node
	[
		id 140488946493872
		label "x"
	]

	edge
	[
		source 140488946493776
		target 140488946493872
		label "right"
	]
	edge
	[
		source 140488946493456
		target 140488946493776
		label "right"
	]
	edge
	[
		source 140488946493408
		target 140488946493456
		label "left"
	]
	node
	[
		id 140488946493920
		label "DIVIDE"
	]

	node
	[
		id 140488946493968
		label "1"
	]

	edge
	[
		source 140488946493920
		target 140488946493968
		label "left"
	]
	node
	[
		id 140488946494016
		label "x"
	]

	edge
	[
		source 140488946493920
		target 140488946494016
		label "right"
	]
	edge
	[
		source 140488946493408
		target 140488946493920
		label "right"
	]
]
