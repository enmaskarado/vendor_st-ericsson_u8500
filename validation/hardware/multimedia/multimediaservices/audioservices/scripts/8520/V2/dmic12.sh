amixer cset iface=MIXER,name='LineIn Right' Disabled
amixer cset iface=MIXER,name='LineIn Left' Disabled
amixer cset iface=MIXER,name='Mic 1' Disabled
amixer cset iface=MIXER,name='Mic 2' Disabled
amixer cset iface=MIXER,name='DMic 1' Enabled
amixer cset iface=MIXER,name='DMic 2' Enabled
amixer cset iface=MIXER,name='DMic 3' Disabled
amixer cset iface=MIXER,name='DMic 4' Disabled
amixer cset iface=MIXER,name='DMic 5' Disabled
amixer cset iface=MIXER,name='DMic 6' Disabled

amixer cset iface=MIXER,name='AD 1 Select Capture Route' 'DMic 1'
amixer cset iface=MIXER,name='AD 2 Select Capture Route' 'DMic 2'
amixer cset iface=MIXER,name='Digital Interface AD To Slot 0 Map' 'AD_OUT1'
amixer cset iface=MIXER,name='Digital Interface AD To Slot 1 Map' 'AD_OUT2'
amixer cset iface=MIXER,name='Digital Interface AD To Slot 2 Map' 'AD_OUT1'
amixer cset iface=MIXER,name='Digital Interface AD To Slot 3 Map' 'AD_OUT2'
amixer cset iface=MIXER,name='Digital Interface AD To Slot 4 Map' 'AD_OUT1'
amixer cset iface=MIXER,name='Digital Interface AD To Slot 5 Map' 'AD_OUT2'
amixer cset iface=MIXER,name='Digital Interface AD To Slot 6 Map' 'AD_OUT1'
amixer cset iface=MIXER,name='Digital Interface AD To Slot 7 Map' 'AD_OUT2'

