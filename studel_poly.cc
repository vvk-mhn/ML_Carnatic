const size = 60
hush()

stack(
  ...Array(size).fill(0).map((_, i) => {
    const noteNum = i
    return n(noteNum)
      .cpm(130 * (i / 48))
      .hsl(i / size, 1, .6)
      .scale("<<f3@4>:major:pentatonic >").lpf(60000/i)
      .s("dantranh:sawtooth:1:2").n("1".add(sine.mul(15)
      .slow(4))).ch(i%16).gain(1)
  })
) 
.decay(4).sustain(.1)
.pan(signal(x => Math.random()).pow(2).speed(.3))
.velocity(signal(x => Math.random()).range(0.7,1))
.pianoroll().clip(.9)

