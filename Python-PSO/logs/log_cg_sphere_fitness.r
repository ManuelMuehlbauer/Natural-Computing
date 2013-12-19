# ---------------------------------------------------------------------------
# This file was automagically outputted by the PyPSO script on 10-08-13
# Call "R --no-save < log_cg_sphere_fitness.r" to let it run and create JPG graphs
# ---------------------------------------------------------------------------
jpeg("log_cg_sphere_fitness.jpg")
d <- read.table("log_cg_sphere.csv", sep=",", header=TRUE)
xrange <- range(d$Iteration)
cols <- c(d[,2],d[,3],d[,4],d[,5])
yrange <- range(cols)
plot(xrange, yrange,type="n",log="y", xlab="Iteration", ylab="Fitness")
lines(d$Iteration,d[,2], lty=1, col="black")
lines(d$Iteration,d[,3], lty=2, col="black")
lines(d$Iteration,d[,4], lty=3, col="green")
lines(d$Iteration,d[,5], lty=4, col="green")
legend(100,max(cols)-max(cols)/10,lty=c(1, 2, 3, 4),legend=c('avg. pbest (circle)', 'gbest so far (circle)', 'avg. pbest (geographical)', 'gbest so far (geographical)'), col=c('black', 'black', 'green', 'green'))
dev.off()
q()
