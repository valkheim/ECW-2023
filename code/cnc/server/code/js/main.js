window.onload = function () {
    setInterval(function () {
        const timers = document.getElementsByClassName("card-timers")
        for (let i = 0; i < timers.length; i++) {
            const timer = timers[i]
            const timestamp = parseInt(timer.children[0].innerText)
            const today = new Date();
            const deadline = new Date(timestamp * 1000);
            const diff = deadline.getTime() - today.getTime();
            const days = Math.ceil(diff / (1000 * 3600 * 24))
            timer.children[1].innerText = `${days} days`
            const hours = Math.ceil(diff / (1000 * 3600) % 24)
            timer.children[2].innerText = `${hours} hours`
            const minutes = Math.ceil(diff / (1000 * 60) % 60)
            timer.children[3].innerText = `${minutes} minutes`
            timer.children[0].innerText = timestamp + 1
        }
    }, 1000)
}
