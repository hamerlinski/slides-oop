<script>
export default {
  data() {
    return {
      countDown: 60*25
    }
  },
  methods: {
    countDownTimer() {
      if (this.countDown > 0) {
        setTimeout(() => {
          this.countDown -= 1
          this.countDownTimer()
        }, 1000)
      }
    }
  },
  created() {
    this.countDownTimer()
  }
}
</script>

<template>
  <h1>Timer: {{ countDown }}</h1>
</template>
