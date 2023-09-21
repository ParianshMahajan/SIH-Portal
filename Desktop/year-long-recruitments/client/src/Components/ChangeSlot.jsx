import styles from "./ChangeSlot.module.css"

const ChangeSlot = () => {
  return (
    <div className={styles.changeSlot}>
      <div className={styles.changeSlotChild} />
      <div className={styles.changeSlotItem} />
      <div className={styles.requestForNewSlotWrapper}>
        <b className={styles.requestForNew1}>Request for new slot</b>
      </div>
      <div className={styles.rectangleParent}>
        <div className={styles.groupChild} />
        <div className={styles.groupItem} />
        <b className={styles.reasonForChange1}>Reason for Change</b>
        <b className={styles.description}>Description</b>
      </div>
      <div className={styles.union}>
        <div className={styles.unionChild} />
        <div className={styles.unionItem} />
      </div>
      <div className={styles.changeSlotInner} />
      <b className={styles.newSlot}>New Slot</b>
      <div className={styles.rectangleGroup}>
        <div className={styles.groupInner} />
        <div className={styles.rectangleDiv} />
        <b className={styles.submit}>SUBMIT</b>
      </div>
      <div className={styles.changeSlotChild1} />
      <div className={styles.changeSlotChild2} />
      <b className={styles.saturday}>Saturday</b>
      <b className={styles.sunday}>Sunday</b>
      <div className={styles.rectangleContainer}>
        <div className={styles.groupChild1} />
        <div className={styles.groupChild2} />
        <div className={styles.groupChild3} />
        <div className={styles.groupChild4} />
        <b className={styles.b}>6: 19 - 9: 16</b>
        <b className={styles.b1}>6: 19 - 9: 16</b>
        <b className={styles.b2}>6: 19 - 9: 16</b>
        <b className={styles.b3}>6: 19 - 9: 16</b>
      </div>
      <img className={styles.changeSlotChild3} alt="" src="Group 20.svg" />
    </div>
  )
}

export default ChangeSlot
