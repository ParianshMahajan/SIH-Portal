import styles from "./PastApplication.module.css"

const PastApplication = () => {
  return (
    <div className={styles.pastApplication}>
      <div className={styles.pastApplicationChild} />
      <div className={styles.pastApplicationItem} />
      <div className={styles.pastApplicationsWrapper}>
        <b className={styles.pastApplications}>Past Applications</b>
      </div>
      <b className={styles.date}>Date</b>
      <b className={styles.review}>Review</b>
      <div className={styles.rectangleParent}>
        <div className={styles.groupChild} />
        <div className={styles.groupItem} />
        <b className={styles.april262023}>{`APRIL 26, 2023 `}</b>
      </div>
      <div className={styles.rectangleGroup}>
        <div className={styles.groupChild} />
        <div className={styles.groupItem} />
        <b className={styles.april262023}>{`APRIL 26, 2023 `}</b>
      </div>
      <div className={styles.rectangleContainer}>
        <div className={styles.groupChild} />
        <div className={styles.groupItem} />
        <b className={styles.april262023}>{`APRIL 26, 2023 `}</b>
      </div>
      <div className={styles.groupDiv}>
        <div className={styles.groupChild} />
        <div className={styles.groupItem} />
        <b className={styles.april262023}>{`APRIL 26, 2023 `}</b>
      </div>
      <img className={styles.pastApplicationInner} alt="" src="Group 20.svg" />
    </div>
  )
}

export default PastApplication
