graph
[
	node
	[
		id 140473503066784
		label "PLUS"
	]

	node
	[
		id 140473503066832
		label "MINUS"
	]

	node
	[
		id 140473506201600
		label "MULTIPLY"
	]

	node
	[
		id 140473506201648
		label "COS"
	]

	node
	[
		id 140473506201696
		label "DIVIDE"
	]

	node
	[
		id 140473506201744
		label "PLUS"
	]

	node
	[
		id 140473506201792
		label "x"
	]

	edge
	[
		source 140473506201744
		target 140473506201792
		label "left"
	]
	node
	[
		id 140473506201840
		label "1"
	]

	edge
	[
		source 140473506201744
		target 140473506201840
		label "right"
	]
	edge
	[
		source 140473506201696
		target 140473506201744
		label "left"
	]
	node
	[
		id 140473506201888
		label "2"
	]

	edge
	[
		source 140473506201696
		target 140473506201888
		label "right"
	]
	edge
	[
		source 140473506201648
		target 140473506201696
		label "left"
	]
	edge
	[
		source 140473506201600
		target 140473506201648
		label "left"
	]
	node
	[
		id 140473506201936
		label "DIVIDE"
	]

	node
	[
		id 140473506202272
		label "2"
	]

	edge
	[
		source 140473506201936
		target 140473506202272
		label "left"
	]
	node
	[
		id 140473506202512
		label "POWER"
	]

	node
	[
		id 140473506202560
		label "2"
	]

	edge
	[
		source 140473506202512
		target 140473506202560
		label "left"
	]
	node
	[
		id 140473506202608
		label "2"
	]

	edge
	[
		source 140473506202512
		target 140473506202608
		label "right"
	]
	edge
	[
		source 140473506201936
		target 140473506202512
		label "right"
	]
	edge
	[
		source 140473506201600
		target 140473506201936
		label "right"
	]
	edge
	[
		source 140473503066832
		target 140473506201600
		label "left"
	]
	node
	[
		id 140473505153024
		label "1"
	]

	edge
	[
		source 140473503066832
		target 140473505153024
		label "right"
	]
	edge
	[
		source 140473503066784
		target 140473503066832
		label "left"
	]
	node
	[
		id 140473506202464
		label "MULTIPLY"
	]

	node
	[
		id 140473506202320
		label "2"
	]

	edge
	[
		source 140473506202464
		target 140473506202320
		label "left"
	]
	node
	[
		id 140473506202368
		label "POWER"
	]

	node
	[
		id 140473506202416
		label "x"
	]

	edge
	[
		source 140473506202368
		target 140473506202416
		label "left"
	]
	node
	[
		id 140473506202656
		label "MINUS"
	]

	node
	[
		id 140473506202704
		label "2"
	]

	edge
	[
		source 140473506202656
		target 140473506202704
		label "left"
	]
	node
	[
		id 140473506202752
		label "1"
	]

	edge
	[
		source 140473506202656
		target 140473506202752
		label "right"
	]
	edge
	[
		source 140473506202368
		target 140473506202656
		label "right"
	]
	edge
	[
		source 140473506202464
		target 140473506202368
		label "right"
	]
	edge
	[
		source 140473503066784
		target 140473506202464
		label "right"
	]
]
