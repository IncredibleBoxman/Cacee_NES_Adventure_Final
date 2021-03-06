;this file for FamiTone2 library generated by FamiStudio
FT_DPCM_PTR=$c000
  .export _Shatterhand_music_data
_Shatterhand_music_data:
	.byte 1
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256



@instruments:
	.byte $30 ;instrument 00 (Bass)
	.word @env5, @env1, @env1
	.byte $00
	.byte $30 ;instrument 01 (BassDrum)
	.word @env10, @env4, @env1
	.byte $00
	.byte $30 ;instrument 02 (CymbalHigh)
	.word @env3, @env9, @env1
	.byte $00
	.byte $30 ;instrument 03 (CymbalLow)
	.word @env8, @env7, @env1
	.byte $00
	.byte $30 ;instrument 04 (Lead-Duty0)
	.word @env6, @env1, @env0
	.byte $00
	.byte $70 ;instrument 05 (Lead-Duty1)
	.word @env6, @env1, @env0
	.byte $00
	.byte $b0 ;instrument 06 (Lead-Duty2)
	.word @env6, @env1, @env0
	.byte $00
	.byte $30 ;instrument 07 (Snare)
	.word @env2, @env9, @env1
	.byte $00

@samples:
@env0:
	.byte $c0,$08,$c0,$04,$bd,$03,$bd,$00,$02
@env1:
	.byte $c0,$7f,$00,$00
@env2:
	.byte $ca,$c6,$c3,$c0,$00,$03
@env3:
	.byte $cb,$ca,$09,$c9,$00,$03
@env4:
	.byte $c0,$bf,$c1,$00,$02
@env5:
	.byte $cf,$7f,$00,$00
@env6:
	.byte $c8,$c9,$c5,$00,$02
@env7:
	.byte $c0,$c2,$c5,$00,$02
@env8:
	.byte $cb,$cb,$c5,$03,$c4,$03,$c3,$03,$c2,$00,$08
@env9:
	.byte $c0,$c1,$c2,$00,$02
@env10:
	.byte $cf,$ca,$c3,$c2,$c0,$00,$04

@song0ch0:
	.byte $fb, $01
@song0ch0loop:
@ref0:
	.byte $88,$2c,$a1,$32,$8d,$2c,$2c,$a1,$36,$8d,$2c,$2c,$a1
@ref1:
	.byte $3c,$8d,$2c,$2c,$a1,$3a,$a1,$36,$8d,$3a,$32,$8d,$36,$28,$8d,$32
@ref2:
	.byte $2c,$a1,$32,$8d,$2c,$2c,$a1,$36,$8d,$2c,$2c,$a1
	.byte $ff,$10
	.word @ref1
@ref3:
	.byte $00,$32,$8d,$4e,$8d,$28,$4a,$8d,$4e,$40,$8d,$4a,$4e,$8d,$40,$4a,$8d,$4e,$40,$8d,$4a,$36,$8d,$40
@ref4:
	.byte $32,$8d,$36,$28,$8d,$32,$3a,$8d,$28,$32,$8d,$3a,$28,$8d,$32,$22,$8d,$28,$28,$8d,$22,$2c,$8d,$28
@ref5:
	.byte $4e,$8d,$2c,$00,$2c,$8d,$3c,$8d,$4e,$00,$4e,$8d,$3c,$8f,$40,$8d,$3c,$00,$3c,$8d,$40,$8f
@ref6:
	.byte $3a,$8d,$40,$00,$40,$8d,$3a,$8f,$3c,$8d,$3a,$00,$3a,$8d,$36,$b3
@ref7:
	.byte $3a,$8d,$36,$00,$36,$8d,$32,$8d,$3a,$36,$d7
@ref8:
	.byte $00,$36,$8d,$22,$8d,$36,$28,$8d,$22,$2c,$8d,$28,$36,$8d,$2c,$32,$8d,$36,$28,$8d,$32,$2c,$8d,$28
@ref9:
	.byte $00,$28,$8d,$2c,$8f,$3c,$8d,$2c,$00,$2c,$8d,$3c,$8f,$40,$8d,$3c,$00,$3c,$8d,$40,$8f
	.byte $ff,$10
	.word @ref6
	.byte $ff,$0b
	.word @ref7
	.byte $ff,$18
	.word @ref8
@ref10:
	.byte $00,$28,$8d,$2c,$8f,$8a,$46,$b3,$4a,$8d,$46,$4e,$8d,$4a,$52,$8d,$4e
@ref11:
	.byte $54,$a1,$58,$8d,$54,$54,$8d,$58,$00,$58,$8d,$4c,$b3
@ref12:
	.byte $46,$c5,$52,$93,$46,$4e,$93,$52,$4c,$93,$4e
@ref13:
	.byte $4e,$a1,$44,$8d,$4e,$54,$a1,$52,$8d,$54,$4e,$8d,$52,$4a,$8d,$4e
@ref14:
	.byte $00,$4e,$8d,$4a,$8f,$46,$b3,$4a,$8d,$46,$4e,$8d,$4a,$52,$8d,$4e
@ref15:
	.byte $4a,$a1,$4e,$8d,$4a,$52,$8d,$4e,$00,$4e,$8d,$54,$b3
@ref16:
	.byte $58,$c5,$58,$8f,$5c,$8d,$58,$62,$8d,$5c,$58,$8d,$62
@ref17:
	.byte $00,$62,$8d,$88,$3c,$8d,$58,$3a,$8d,$3c,$32,$8d,$3a,$24,$8d,$32,$22,$8d,$24,$28,$8d,$22,$2c,$8d,$28
	.byte $ff,$16
	.word @ref5
	.byte $ff,$10
	.word @ref6
	.byte $ff,$0b
	.word @ref7
	.byte $ff,$18
	.word @ref8
	.byte $ff,$15
	.word @ref9
	.byte $ff,$10
	.word @ref6
	.byte $ff,$0b
	.word @ref7
	.byte $ff,$18
	.word @ref8
@ref18:
	.byte $00,$28,$8d,$2c,$8f,$4a,$a1,$4a,$8f,$4e,$8d,$4a,$52,$8d,$4e,$52,$8f
@ref19:
	.byte $a3,$52,$8f,$4e,$8d,$52,$00,$52,$8d,$4c,$b3
@ref20:
	.byte $4e,$c5,$4e,$8f,$52,$8d,$4e,$54,$8d,$52,$58,$8f
@ref21:
	.byte $a3,$54,$8d,$58,$52,$8d,$54,$00,$54,$8d,$4e,$b3
@ref22:
	.byte $00,$4e,$9f,$52,$a1,$52,$8f,$54,$8d,$52,$58,$8d,$54,$5c,$8f
@ref23:
	.byte $a3,$58,$8d,$5c,$54,$8d,$58,$00,$58,$8d,$58,$8d,$54,$54,$8d,$58,$52,$8d,$54
@ref24:
	.byte $4c,$c5,$4e,$c5
@ref25:
	.byte $52,$8d,$4e,$52,$8f,$00,$52,$8d,$52,$d7
@ref26:
	.byte $5c,$8d,$52,$4e,$8d,$5c,$44,$8d,$4e,$58,$8d,$44,$4a,$8d,$58,$40,$8d,$4a,$3c,$a1
@ref27:
	.byte $00,$3c,$8d,$3c,$8f,$3a,$8d,$3c,$32,$8d,$3a,$3c,$8d,$32,$3a,$8d,$3c,$32,$8d,$3a,$36,$8d,$32
@ref28:
	.byte $3c,$8d,$36,$3c,$8f,$00,$3c,$8d,$40,$8d,$3c,$40,$8f,$00,$40,$8d,$3c,$8d,$40,$3c,$8f
@ref29:
	.byte $00,$3c,$8d,$40,$89,$41,$3c,$40,$8f,$00,$40,$8d,$4e,$8d,$40,$4a,$8d,$4e,$46,$8d,$4a,$44,$8d,$46
@ref30:
	.byte $5c,$8d,$44,$4e,$8d,$5c,$44,$8d,$4e,$58,$8d,$44,$4a,$8d,$58,$40,$8d,$4a,$3c,$a1
	.byte $ff,$17
	.word @ref27
	.byte $ff,$15
	.word @ref28
	.byte $ff,$18
	.word @ref29
@ref31:
	.byte $2e,$a1,$3c,$8d,$2e,$32,$a1,$40,$a1,$36,$8f
@ref32:
	.byte $91,$44,$a1,$52,$8d,$44,$54,$8d,$52,$8f,$54,$4e,$8d,$52,$4a,$8d,$4e
@ref33:
	.byte $54,$8d,$4a,$54,$8f,$00,$54,$8d,$52,$8d,$54,$52,$8f,$00,$52,$8d,$54,$8d,$52,$54,$8f
@ref34:
	.byte $00,$54,$8d,$22,$8d,$54,$2c,$8d,$22,$3a,$8d,$2c,$4a,$8d,$3a,$52,$b3
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@song0ch1loop:
@ref35:
	.byte $8a,$36,$a1,$3c,$8d,$36,$36,$a1,$40,$8d,$36,$36,$a1
@ref36:
	.byte $44,$8d,$36,$36,$a1,$40,$a1,$3c,$8d,$40,$3a,$8d,$3c,$32,$8d,$3a
@ref37:
	.byte $36,$a1,$3c,$8d,$36,$36,$a1,$40,$8d,$36,$36,$a1
	.byte $ff,$10
	.word @ref36
@ref38:
	.byte $00,$3a,$8d,$54,$8d,$32,$52,$8d,$54,$4a,$8d,$52,$54,$8d,$4a,$52,$8d,$54,$4a,$8d,$52,$3c,$8d,$4a
@ref39:
	.byte $3a,$8d,$3c,$32,$8d,$3a,$40,$8d,$32,$3a,$8d,$40,$32,$8d,$3a,$2c,$8d,$32,$32,$8d,$2c,$36,$8d,$32
@ref40:
	.byte $66,$8d,$36,$00,$36,$8d,$44,$8d,$66,$00,$66,$8d,$44,$8f,$46,$8d,$44,$00,$44,$8d,$46,$8f
@ref41:
	.byte $40,$8d,$46,$00,$46,$8d,$40,$8f,$44,$8d,$40,$00,$40,$8d,$3c,$b3
@ref42:
	.byte $40,$8d,$3c,$00,$3c,$8d,$3a,$8d,$40,$3c,$d7
@ref43:
	.byte $00,$3c,$8d,$2c,$8d,$3c,$32,$8d,$2c,$36,$8d,$32,$3c,$8d,$36,$3a,$8d,$3c,$32,$8d,$3a,$36,$8d,$32
@ref44:
	.byte $00,$32,$8d,$36,$8f,$44,$8d,$36,$00,$36,$8d,$44,$8f,$46,$8d,$44,$00,$44,$8d,$46,$8f
	.byte $ff,$10
	.word @ref41
	.byte $ff,$0b
	.word @ref42
	.byte $ff,$18
	.word @ref43
@ref45:
	.byte $00,$32,$8d,$36,$8f,$8c,$4e,$b3,$52,$8d,$4e,$54,$8d,$52,$58,$8d,$54
@ref46:
	.byte $5c,$a1,$5e,$8d,$5c,$5c,$8d,$5e,$00,$5e,$8d,$52,$b3
@ref47:
	.byte $58,$c5,$58,$95,$54,$93,$58,$52,$93,$54
@ref48:
	.byte $54,$a1,$4e,$8d,$54,$5c,$d7
@ref49:
	.byte $00,$5c,$9f,$4e,$b3,$52,$8d,$4e,$54,$8d,$52,$58,$8d,$54
@ref50:
	.byte $5c,$a1,$5e,$8d,$5c,$62,$8d,$5e,$00,$5e,$8d,$66,$b3
@ref51:
	.byte $6a,$c5,$6a,$8f,$6c,$8d,$6a,$70,$8d,$6c,$6a,$8d,$70
@ref52:
	.byte $00,$70,$8d,$8a,$54,$8d,$6a,$52,$8d,$54,$4a,$8d,$52,$3c,$8d,$4a,$3a,$8d,$3c,$32,$8d,$3a,$36,$8d,$32
	.byte $ff,$16
	.word @ref40
	.byte $ff,$10
	.word @ref41
	.byte $ff,$0b
	.word @ref42
	.byte $ff,$18
	.word @ref43
	.byte $ff,$15
	.word @ref44
	.byte $ff,$10
	.word @ref41
	.byte $ff,$0b
	.word @ref42
	.byte $ff,$18
	.word @ref43
@ref53:
	.byte $00,$32,$8d,$36,$8f,$52,$a1,$52,$8f,$54,$8d,$52,$58,$8d,$54,$5c,$8f
@ref54:
	.byte $a3,$58,$8d,$5c,$54,$8d,$58,$00,$58,$8d,$52,$b3
@ref55:
	.byte $54,$c5,$54,$8f,$58,$8d,$54,$5c,$8d,$58,$5e,$8f
@ref56:
	.byte $a3,$5c,$8d,$5e,$58,$8d,$5c,$00,$5c,$8d,$54,$b3
@ref57:
	.byte $00,$54,$9f,$58,$a1,$58,$8f,$5c,$8d,$58,$5e,$8d,$5c,$62,$8f
@ref58:
	.byte $a3,$5e,$8d,$62,$5c,$8d,$5e,$00,$5e,$8d,$5e,$8d,$5c,$5c,$8d,$5e,$58,$8d,$5c
@ref59:
	.byte $5c,$c5,$60,$c5
@ref60:
	.byte $62,$8d,$60,$62,$8f,$00,$62,$8d,$64,$d7
@ref61:
	.byte $66,$8d,$64,$5c,$8d,$66,$4e,$8d,$5c,$62,$8d,$4e,$58,$8d,$62,$4a,$8d,$58,$46,$a1
@ref62:
	.byte $00,$46,$8d,$54,$8d,$46,$52,$8d,$54,$4a,$8d,$52,$54,$8d,$4a,$52,$8d,$54,$4a,$8d,$52,$4e,$8d,$4a
@ref63:
	.byte $46,$8d,$4e,$46,$8f,$00,$46,$8d,$4a,$8d,$46,$4a,$8f,$00,$4a,$8d,$4e,$8d,$4a,$4e,$8f
@ref64:
	.byte $00,$4e,$8d,$52,$8d,$4e,$52,$8f,$00,$52,$8d,$54,$8d,$52,$52,$8d,$54,$4e,$8d,$52,$4a,$8d,$4e
@ref65:
	.byte $66,$8d,$4a,$5c,$8d,$66,$4e,$8d,$5c,$62,$8d,$4e,$58,$8d,$62,$4a,$8d,$58,$46,$a1
	.byte $ff,$18
	.word @ref62
	.byte $ff,$15
	.word @ref63
	.byte $ff,$17
	.word @ref64
@ref66:
	.byte $46,$a1,$54,$8d,$46,$4a,$a1,$58,$a1,$4e,$8f
@ref67:
	.byte $91,$5c,$a1,$6a,$8d,$5c,$6c,$8d,$6a,$6a,$8d,$6c,$66,$8d,$6a,$62,$8d,$66
@ref68:
	.byte $66,$8d,$62,$66,$8f,$00,$66,$8d,$62,$8d,$66,$62,$8f,$00,$62,$8d,$66,$8d,$62,$66,$8f
@ref69:
	.byte $00,$66,$8d,$2c,$8d,$66,$3a,$8d,$2c,$44,$8d,$3a,$52,$8d,$44,$5c,$b3
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@song0ch2loop:
@ref70:
	.byte $80,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$00,$81
@ref71:
	.byte $36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$32,$9d,$01,$2c,$8b,$01,$32,$8b,$01,$3a,$8b,$00,$81
@ref72:
	.byte $36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$36,$8b,$00,$81
	.byte $ff,$16
	.word @ref71
@ref73:
	.byte $32,$f7,$01,$32,$8f
@ref74:
	.byte $c3,$01,$32,$8b,$01,$2c,$8b,$01,$32,$8b,$01,$36,$8b,$00,$81
	.byte $ff,$19
	.word @ref72
	.byte $ff,$19
	.word @ref72
	.byte $ff,$19
	.word @ref72
@ref75:
	.byte $36,$8b,$01,$2c,$8b,$01,$32,$8b,$01,$36,$8b,$01,$3c,$8b,$01,$3a,$8b,$01,$32,$8b,$01,$36,$8b,$00,$81
@ref76:
	.byte $2e,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$2e,$8b,$00,$81
	.byte $ff,$19
	.word @ref76
	.byte $ff,$19
	.word @ref76
@ref77:
	.byte $2e,$8b,$01,$2c,$8b,$01,$32,$8b,$01,$36,$8b,$01,$3c,$8b,$01,$3a,$8b,$01,$32,$8b,$01,$36,$8b,$00,$81
@ref78:
	.byte $28,$8b,$01,$28,$8b,$01,$36,$8b,$01,$3c,$8b,$01,$28,$8b,$01,$28,$8b,$01,$36,$8b,$01,$3c,$8b,$00,$81
@ref79:
	.byte $2c,$8b,$01,$2c,$8b,$01,$3a,$8b,$01,$40,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$3a,$8b,$01,$40,$8b,$00,$81
@ref80:
	.byte $28,$8b,$01,$28,$8b,$01,$36,$8b,$01,$3c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$3a,$8b,$01,$40,$8b,$00,$81
@ref81:
	.byte $36,$8b,$01,$36,$8b,$01,$32,$8b,$01,$32,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$2c,$8b,$01,$2c,$8b,$00,$81
	.byte $ff,$19
	.word @ref78
	.byte $ff,$19
	.word @ref79
@ref82:
	.byte $2e,$8b,$01,$2e,$8b,$01,$3c,$8b,$01,$46,$8b,$01,$2e,$8b,$01,$3c,$8b,$01,$46,$8b,$01,$32,$8b,$00,$81
@ref83:
	.byte $91,$32,$8b,$01,$32,$9d,$01,$32,$8b,$01,$32,$9d,$01,$36,$8b,$00,$81
	.byte $ff,$19
	.word @ref72
	.byte $ff,$19
	.word @ref72
	.byte $ff,$19
	.word @ref72
	.byte $ff,$19
	.word @ref75
	.byte $ff,$19
	.word @ref76
	.byte $ff,$19
	.word @ref76
	.byte $ff,$19
	.word @ref76
	.byte $ff,$19
	.word @ref77
@ref84:
	.byte $32,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$00,$81
@ref85:
	.byte $34,$8b,$01,$34,$8b,$01,$34,$8b,$01,$34,$8b,$01,$34,$8b,$01,$34,$8b,$01,$34,$8b,$01,$34,$8b,$00,$81
	.byte $ff,$19
	.word @ref72
@ref86:
	.byte $38,$8b,$01,$38,$8b,$01,$38,$8b,$01,$38,$8b,$01,$38,$8b,$01,$38,$8b,$01,$38,$8b,$01,$38,$8b,$00,$81
@ref87:
	.byte $3a,$8b,$01,$3a,$8b,$01,$3a,$8b,$01,$3a,$8b,$01,$3a,$8b,$01,$3a,$8b,$01,$3a,$8b,$01,$3a,$8b,$00,$81
	.byte $ff,$19
	.word @ref84
@ref88:
	.byte $2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$00,$81
@ref89:
	.byte $2c,$8b,$01,$2c,$8b,$01,$3a,$8b,$01,$44,$9d,$01,$44,$8b,$01,$3a,$8b,$01,$2c,$8b,$00,$81
@ref90:
	.byte $36,$8b,$01,$36,$8b,$01,$36,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$01,$2e,$a1
@ref91:
	.byte $8d,$01,$2e,$8b,$01,$2e,$9d,$01,$2e,$8b,$01,$2e,$9d,$01,$2e,$8b,$00,$81
@ref92:
	.byte $28,$8b,$01,$28,$8b,$01,$28,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2e,$8b,$01,$2e,$8b,$00,$81
@ref93:
	.byte $2e,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$32,$8b,$01,$32,$8b,$00,$81
	.byte $ff,$14
	.word @ref90
	.byte $ff,$12
	.word @ref91
	.byte $ff,$19
	.word @ref92
	.byte $ff,$19
	.word @ref93
@ref94:
	.byte $28,$8b,$01,$28,$8b,$01,$28,$8b,$01,$28,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$00,$81
@ref95:
	.byte $2e,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$2e,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$01,$32,$8b,$00,$81
@ref96:
	.byte $36,$8b,$01,$36,$8b,$00,$93,$32,$8b,$01,$32,$8b,$00,$93,$36,$8b,$01,$36,$8b,$00,$81
@ref97:
	.byte $91,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$2c,$8b,$01,$30,$8b,$01,$34,$8b,$00,$81
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@song0ch3loop:
@ref98:
	.byte $84,$5a,$a1,$86,$4e,$a1,$84,$5a,$a1,$86,$4e,$a1
	.byte $ff,$08
	.word @ref98
	.byte $ff,$08
	.word @ref98
	.byte $ff,$08
	.word @ref98
@ref99:
	.byte $84,$5a,$a1,$5a,$a1,$5a,$a1,$5a,$a1
@ref100:
	.byte $5a,$a1,$5a,$a1,$86,$4e,$8f,$84,$5a,$8f,$86,$4f,$4e,$8b,$84,$5a,$8f
@ref101:
	.byte $82,$42,$8f,$8e,$5a,$8f,$86,$4e,$8f,$8e,$5a,$8f,$82,$42,$8f,$42,$8f,$86,$4e,$8f,$8e,$5a,$8f
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
@ref102:
	.byte $82,$42,$8f,$86,$4e,$8f,$4e,$8f,$82,$42,$8f,$86,$4e,$8f,$4e,$8f,$82,$42,$8f,$86,$4e,$8f
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref102
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
@ref103:
	.byte $86,$4e,$8f,$82,$42,$8f,$42,$8f,$86,$4e,$8f,$82,$42,$8f,$86,$4e,$8f,$4e,$8f,$4e,$8f
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref102
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref102
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
	.byte $ff,$10
	.word @ref101
@ref104:
	.byte $86,$4e,$8f,$4e,$8f,$82,$42,$8f,$86,$4e,$8f,$82,$42,$8f,$86,$4e,$8f,$4e,$8f,$4e,$8f
@ref105:
	.byte $4e,$8f,$4e,$a1,$4e,$8f,$4e,$a1,$4e,$8f,$4e,$8f
@ref106:
	.byte $91,$82,$42,$8f,$86,$4e,$8f,$82,$42,$8f,$86,$4e,$8f,$82,$42,$8f,$86,$4e,$8f,$4e,$8f
@ref107:
	.byte $82,$42,$8f,$42,$8f,$84,$5a,$8f,$82,$42,$8f,$42,$8f,$84,$5a,$8f,$82,$42,$8f,$42,$8f
@ref108:
	.byte $84,$5a,$8f,$82,$42,$8f,$42,$8f,$84,$5a,$8f,$86,$4e,$a1,$4e,$a1
	.byte $ff,$0c
	.word @ref105
	.byte $ff,$0f
	.word @ref106
	.byte $ff,$10
	.word @ref107
	.byte $ff,$0c
	.word @ref108
	.byte $ff,$08
	.word @ref98
	.byte $ff,$08
	.word @ref98
	.byte $ff,$0c
	.word @ref105
@ref109:
	.byte $91,$4e,$8f,$4e,$8f,$4e,$8f,$4e,$8f,$4e,$8f,$82,$42,$8f,$42,$8f
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@song0ch4loop:
@ref110:
	.byte $f9,$95
@ref111:
	.byte $f9,$95
@ref112:
	.byte $f9,$95
@ref113:
	.byte $f9,$95
@ref114:
	.byte $f9,$95
@ref115:
	.byte $f9,$95
@ref116:
	.byte $f9,$95
@ref117:
	.byte $f9,$95
@ref118:
	.byte $f9,$95
@ref119:
	.byte $f9,$95
@ref120:
	.byte $f9,$95
@ref121:
	.byte $f9,$95
@ref122:
	.byte $f9,$95
@ref123:
	.byte $f9,$95
@ref124:
	.byte $f9,$95
@ref125:
	.byte $f9,$95
@ref126:
	.byte $f9,$95
@ref127:
	.byte $f9,$95
@ref128:
	.byte $f9,$95
@ref129:
	.byte $f9,$95
@ref130:
	.byte $f9,$95
@ref131:
	.byte $f9,$95
@ref132:
	.byte $f9,$95
@ref133:
	.byte $f9,$95
@ref134:
	.byte $f9,$95
@ref135:
	.byte $f9,$95
@ref136:
	.byte $f9,$95
@ref137:
	.byte $f9,$95
@ref138:
	.byte $f9,$95
@ref139:
	.byte $f9,$95
@ref140:
	.byte $f9,$95
@ref141:
	.byte $f9,$95
@ref142:
	.byte $f9,$95
@ref143:
	.byte $f9,$95
@ref144:
	.byte $f9,$95
@ref145:
	.byte $f9,$95
@ref146:
	.byte $f9,$95
@ref147:
	.byte $f9,$95
@ref148:
	.byte $f9,$95
@ref149:
	.byte $f9,$95
@ref150:
	.byte $f9,$95
@ref151:
	.byte $f9,$95
@ref152:
	.byte $f9,$95
@ref153:
	.byte $f9,$95
@ref154:
	.byte $f9,$95
@ref155:
	.byte $f9,$95
@ref156:
	.byte $f9,$95
@ref157:
	.byte $f9,$95
@ref158:
	.byte $f9,$95
@ref159:
	.byte $f9,$95
	.byte $fd
	.word @song0ch4loop

